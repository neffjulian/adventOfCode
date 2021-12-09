#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<int> VI;
typedef std::vector<VI> VII;

int rows, cols, curr_component = 0;

void fillMatrix(VII &matrix) {
  std::string input;
  while(std::cin >> input) {
    VI input_to_vector(input.size());
    
    for(size_t i = 0; i < input.size(); i++) {
      input_to_vector[i] = (int)input[i] - 48;
    }
    
    matrix.push_back(input_to_vector);
  }
  
  rows = matrix.size();
  cols = matrix[0].size();
}

int isLocalMin(VII &matrix, int i, int j) {
  bool localMin = true;
  
  if(j > 0) localMin = matrix[i][j] < matrix[i][j-1] && localMin; 
  if(j < cols-1) localMin = matrix[i][j] < matrix[i][j+1] && localMin;
  if(i > 0) localMin = matrix[i][j] < matrix[i-1][j] && localMin;
  if(i < rows-1) localMin = matrix[i][j] < matrix[i+1][j] && localMin;
  
  return localMin * (matrix[i][j] + 1);
}

void funcA() {
  VII matrix;
  fillMatrix(matrix);

  int count = 0;
  
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      count += isLocalMin(matrix, i, j);
    }
  }
  std::cout << count << "\n";
}

void dfs(VII &matrix, VII &components, int i, int j, int min) {
  components[i][j] = curr_component;
    
  if(j > 0 && matrix[i][j] < matrix[i][j-1] && components[i][j-1] == 0 && matrix[i][j-1] != 9) dfs(matrix, components, i, j-1, matrix[i][j]);  
  if(j < cols-1 && matrix[i][j] < matrix[i][j+1] && components[i][j+1] == 0 && matrix[i][j+1] != 9) dfs(matrix, components, i, j+1, matrix[i][j]); 
  if(i > 0 &&  matrix[i][j] < matrix[i-1][j] && components[i-1][j] == 0 && matrix[i-1][j] != 9) dfs(matrix, components, i-1, j, matrix[i][j]); 
  if(i < rows-1 && matrix[i][j] < matrix[i+1][j] && components[i+1][j] == 0 && matrix[i+1][j] != 9) dfs(matrix, components, i+1, j, matrix[i][j]); 
}

void funcB() {
  VII matrix;
  fillMatrix(matrix);
  
  VII components(rows, std::vector<int>(cols, 0));
  curr_component = 0;

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(isLocalMin(matrix, i, j) && matrix[i][j] != 9) {
        curr_component++;
        dfs(matrix, components, i, j, matrix[i][j]);
      }
    }
  }
  
  VI component_sizes(curr_component+1, 0);
  
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(components[i][j]) {
        component_sizes[components[i][j]]++;
      }
    }
  }
  
  std::sort(component_sizes.begin(), component_sizes.end(), std::greater<int>());
  std::cout << component_sizes[0] * component_sizes[1] * component_sizes[2];
}


int main() {
  std::ios_base::sync_with_stdio(false);
  funcA();
  funcB();
}
