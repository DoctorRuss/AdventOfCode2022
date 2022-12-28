#include "Day7.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

class Directory
{
public:
    Directory():m_parent(nullptr), m_name("/"), m_directorySize(0) {};
    Directory(const std::string& name, Directory* parent) : m_parent(parent), m_name(name), m_directorySize(0) {
        m_parent->AddChild(this);
    };
    ~Directory() {
        delete m_parent;
    }
    std::string GetPath() const
    {
        if (m_parent) return m_parent->GetPath() + "/" + m_name;
        else return m_name;
    }
    Directory* GetParent() const { return m_parent; };

    int64_t GetDirectorySize() const { return m_directorySize; }
    int64_t GetTreeSize() const { 
        int64_t treeSize(m_directorySize);
        for (Directory* child : m_children) {
            treeSize += child->GetTreeSize();
        }
        return treeSize; 
    }
    void AddFileSize(const int64_t a_directorySize ) { m_directorySize += a_directorySize; }
    void AddChild(Directory* child) { m_children.push_back(child); };
    std::vector<Directory*> GetChildren() const { return m_children; };
private:
    std::string m_name;
    Directory* m_parent;
    int64_t m_directorySize;
    std::vector<Directory*> m_children;
};

int64_t
SearchForDirectory(Directory* dir, const int treeSize)
{
    int64_t treesizeSum(0);
    if (dir->GetTreeSize() < treeSize)
    {
        //std::cout << dir->GetPath() << " has tree size " << dir->GetTreeSize() << std::endl;
        treesizeSum = dir->GetTreeSize();
    }
    for (Directory* child : dir->GetChildren()) {
        treesizeSum += SearchForDirectory(child, treeSize);
    }
    return treesizeSum;
}

int64_t
SearchForFreeingDirectory(Directory* dir, const int directorySize)
{
    int64_t treesizeSum(std::numeric_limits<int64_t>::max());
    if (dir->GetTreeSize() > directorySize)
    {
        //std::cout << dir->GetPath() << " has tree size " << dir->GetTreeSize() << std::endl;
        treesizeSum = std::min(treesizeSum, dir->GetTreeSize());
    }
    for (Directory* child : dir->GetChildren()) {
        treesizeSum = std::min(treesizeSum, SearchForFreeingDirectory(child, directorySize));
    }
    return treesizeSum;
}


void
Day7::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);

    std::string line;
    std::map<std::string, int64_t> fileSizes;
    Directory root;
    Directory* pwd = &root;
    while (std::getline(filestream, line))
    {
        // handle cd commands
        if (line.substr(0, 5) == "$ cd ")
        {
            std::string newDir = line.substr(5);
            if (newDir == "/")
                pwd = &root;
            else if (newDir == "..")
            {
                pwd = pwd->GetParent();
            }
            else {
                pwd =  new Directory(newDir, pwd);
            }
            //std::cout << pwd->GetPath() << std::endl;
        }
        else if (line.substr(0, 4) == "dir ")
        {
            //std::cout << "Found new dir " << pwd->GetPath() + "/" + line.substr(4) << std::endl;
        }
        else if (line.substr(0, 4) == "$ ls")
        { // ignore
        }
        else
        {
            pwd->AddFileSize(std::stoi(line.substr(0, line.find_first_of(" "))));
        }
        //std::cout << "Currently in " << pwd->GetPath() << " with directory size " << pwd->GetDirectorySize() 
        //    << " and tree size " << pwd->GetTreeSize() << std::endl;
    }
    std::cout << "Total sum " << SearchForDirectory(&root, 100000) << std::endl;
    
    int64_t diskSize(70000000);
    int64_t freeSize(30000000);
    int64_t rootSize = root.GetTreeSize();
    std::cout << "Root takes up " << rootSize << ", requiring " << freeSize - (diskSize - rootSize) << " to be freed" << std::endl;

    std::cout << "Need to free " << SearchForFreeingDirectory(&root, freeSize - (diskSize - rootSize)) << std::endl;
}

