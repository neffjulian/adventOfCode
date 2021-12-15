#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>


typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, 
                              boost::property<boost::edge_weight_t, int>> weighted_graph;
                              
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor edge_desc;
typedef boost::graph_traits<weighted_graph>::vertex_descriptor vertex_desc;

typedef std::vector<int> VI;
typedef std::vector<VI> VII;

int dijkstra_dist(const weighted_graph &G, int s, int t) {
  int n = boost::num_vertices(G);
  std::vector<int> dist_map(n);

  boost::dijkstra_shortest_paths(G, s,
    boost::distance_map(boost::make_iterator_property_map(
      dist_map.begin(), boost::get(boost::vertex_index, G))));

  return dist_map[t];
}

int dijkstra_path(const weighted_graph &G, int s, int t, std::vector<vertex_desc> &path) {
  int n = boost::num_vertices(G);
  std::vector<int>         dist_map(n);
  std::vector<vertex_desc> pred_map(n);

  boost::dijkstra_shortest_paths(G, s,
    boost::distance_map(boost::make_iterator_property_map(
      dist_map.begin(), boost::get(boost::vertex_index, G)))
    .predecessor_map(boost::make_iterator_property_map(
      pred_map.begin(), boost::get(boost::vertex_index, G))));

  int cur = t;
  path.clear(); path.push_back(cur);
  while (s != cur) {
    cur = pred_map[cur];
    path.push_back(cur);
  }
  std::reverse(path.begin(), path.end());
  return dist_map[t];
}

int index(int i, int j) {
  return i*505 + j;
}

void dijkstra(VII &mat) {
  int len = mat[0].size();
  int wid = mat.size();
  
  weighted_graph  G(len * wid);
  weight_map weights = boost::get(boost::edge_weight, G);
  
  edge_desc e;
  
  for(int i = 0; i < len; i++) {
    for(int j = 0; j < wid; j++) {
      if(i > 0) {
        e = boost::add_edge(index(i-1,j), index(i,j), G).first; weights[e] = mat[i][j];
      }
      if(i < len-1) {
        e = boost::add_edge(index(i+1,j), index(i,j), G).first; weights[e] = mat[i][j];
      }
      if(j > 0) {    
        e = boost::add_edge(index(i,j-1), index(i,j), G).first; weights[e] = mat[i][j];
      }
      if(i < wid-1) {
        e = boost::add_edge(index(i,j+1), index(i,j), G).first; weights[e] = mat[i][j];
      }
    }
  }
  std::cout << dijkstra_dist(G, 0, index(wid-1, len-1)) << "\n";
}

void funcA() {
  std::string input;
  VII mat;
  while(std::cin >> input) {
    VI vec;
    for(size_t i = 0; i < input.size(); i++) {
      vec.push_back(input[i] - 48);
    }
    mat.push_back(vec);
  }
  dijkstra(mat);
}

int newCost(VII &mat, int i, int j, int inc) {
  return mat[i][j] + inc > 9 ? mat[i][j] + inc - 9 : mat[i][j] + inc;
}

void funcB() {
  std::string input;
  VII mat;
  while(std::cin >> input) {
    VI vec;
    for(size_t i = 0; i < input.size(); i++) {
      vec.push_back(input[i] - 48);
    }
    mat.push_back(vec);
  }
  
  int len = mat[0].size();
  int wid = mat.size();
  VII matB(len*5, VI(wid*5));
  
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      for(int k = 0; k < len; k++) {
        for(int l = 0; l < wid; l++) {
          if(i > 0 && j > 0) {
            matB[k + len * i][l + wid * j] = newCost(matB, k + len * (i-1), l + wid * (j-1), 2);
          } else if (i > 0) {
            matB[k + len * i][l] = newCost(matB, k + len * (i-1), l, 1);
          } else if( j > 0) {
            matB[k][l + wid * j] = newCost(matB, k, l + wid * (j-1), 1);
          } else {
            matB[k][l] = mat[k][l];
          }
        }
      }
    }
  }
  dijkstra(matB);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  // funcA();
  funcB();
}
