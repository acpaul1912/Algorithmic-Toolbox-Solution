#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(),segments.end(), [](Segment& a, Segment& b) {
    return a.start < b.start;
  });

  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
      
      int temp = i;
      int start = segments[i].start;
      int end = segments[i].end;
      //points.push_back(end);
      for(int j = i+1; j < segments.size() ; j++) {

        if(segments[j].start > end){          
          break;
        }
        else {

          if(end > segments[j].end)  
            end = segments[j].end ;

          i++;
        }
    }
    points.push_back(end);
  }
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
