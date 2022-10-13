#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
template <typename T>
struct directed_graph {
    std::map<T, std::set<T>> edges;

    void connect(T a, T b) {
        edges[b].insert(a);
    }
    directed_graph<string> readFromFile(const std::string &filePath) {
        directed_graph<string> g;
        ifstream infile(filePath);
        cout<<filePath;
        string vertexStart,vertexEnd;
        if (infile.is_open())
        {
            cout << "\n File successfully open" << endl;
            while (infile >> vertexStart && infile >> vertexEnd)
            {
                cout<<vertexStart<<" "<< vertexEnd<<"\n";
                g.connect(vertexStart, vertexEnd);
            }
            return g;
        }
        else
        {
            cout << "Error opening file";
        }
    }
    void writeToFile(std::vector<T>& result) {
        ofstream outfile (R"(E:\VS_projects\Algorithms\govern.out)");
        std::for_each(result.rbegin(),
                      result.rend(),
                      [&outfile](const auto &elem) {
                          outfile << elem << endl;
                      });

        outfile << std::endl;
        outfile.close();
    }
    std::vector<T> toposort() {
        std::set<T> visited;
        std::vector<T> result;
        for (auto const& v : edges) {
            if (visited.find(v.first) == visited.end()) {
                dfs(visited, v.first, result);
            }
        }
        return result;
    }
    void dfs(std::set<T>& visited, const T& v, std::vector<T>& result) {
        visited.insert(v);
        for (auto const& e : edges[v]) {
            if (visited.find(e) == visited.end()) {
                dfs(visited, e, result);
            }
        }

        result.push_back(v);
    }
};

int main(int argc, char* argv[])
{
    int n;
    directed_graph<std::string> g;
    g = g.readFromFile(R"(E:\VS_projects\Algorithms\govern.in)");
    auto result = g.toposort();
    g.writeToFile(result);
    return 0;
}