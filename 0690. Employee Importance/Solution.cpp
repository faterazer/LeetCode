#include <unordered_map>
#include <vector>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int, Employee*> id2Employee;
        for (Employee *employee : employees)
            id2Employee[employee->id] = employee;
        return dfs(id2Employee, id);    
    }
private:
    int dfs(const unordered_map<int, Employee*> &umap, int id)
    {
        int total = umap.at(id)->importance;
        for (const int &subId : umap.at(id)->subordinates)
            total += dfs(umap, subId);
        return total;
    }
};
