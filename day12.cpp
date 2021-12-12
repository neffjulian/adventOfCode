#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>

void dfsA(std::map<std::string, std::vector<std::string>> &graph, const std::string &s, std::map<std::string, bool> visited, int &ctr) {
  if(s == "end") {
    ctr++;
    return;
  } else {
    if(visited[s])
      return;
    if(islower(s[0]))
      visited[s] = true;
      
    std::vector<std::string> neighbors = graph[s];

    for(auto &n : neighbors) {
      dfsA(graph, n, visited, ctr);
    }
    
    if(islower(s[0]) && s!= "start")
    visited[s] = false;
  }
}

void funcA() {
  std::string input, u, v;
  std::map<std::string, std::vector<std::string>> graph;
  while(std::cin >> input) {
      int pos = input.find('-');
      u = input.substr(0, pos);
      v = input.substr(pos+1, input.size()-pos-1);
      graph[u].push_back(v);
      graph[v].push_back(u);
  }

  int ctr = 0;

  std::map<std::string, bool> visited;

  for(auto &[key, value]: graph) {
      visited[key] = false;
  }

  dfsA(graph, "start", visited, ctr);
  std::cout << ctr << "\n";
}

bool visTwice = false;
std::string svisTwice = "";

void dfsB(std::map<std::string, std::vector<std::string>> &graph, const std::string &s, std::map<std::string, bool> visited, int &ctr) {
  if(s == "end") {
    ctr++;
    return;
  } else {
    if(visited[s] && s=="start")
      return;

    if(visited[s] && visTwice && s!="start")
      return;
  
      if(visited[s] && s!="start") {
          visTwice = true;
          svisTwice = s;
      }
      else if(islower(s[0]))
          visited[s] = true;
    
    std::vector<std::string> neighbors = graph[s];

    for(auto &n : neighbors) {
            dfsB(graph, n, visited, ctr);
    }
    
    if(s == svisTwice) {
      svisTwice = "";
      visTwice = false;
      visited[s] = false;
    } else {
      if(islower(s[0]) && s!= "start")
        visited[s] = false;
    }
  }
}


void funcB() {
  std::string input, u, v;
  std::map<std::string, std::vector<std::string>> graph;
  while(std::cin >> input) {
      int pos = input.find('-');
      u = input.substr(0, pos);
      v = input.substr(pos+1, input.size()-pos-1);
      graph[u].push_back(v);
      graph[v].push_back(u);
  }

  int ctr = 0;

  std::map<std::string, bool> visited;

  for(auto &[key, value]: graph) {
      visited[key] = false;
  }

  dfsB(graph, "start", visited, ctr);
  std::cout << ctr << "\n";
}

int main() {
  // funcA();
  funcB();
}
