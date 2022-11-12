#include<bits/stdc++.h>

struct Location{
    size_t row_;
    size_t col_;
};

using Locations = std::vector<Location>;

struct Matrix 
{   
    private:
        size_t rows_;
        size_t cols_;
        std::unique_ptr<int[]> data_;

    public:
        explicit Matrix(size_t rows, size_t cols, const Locations& walls) :
        rows_{rows}, cols_{cols}, data_(new int[rows * cols])

        {InitializeMatrix(walls);}

        void InitializeMatrix(const Locations& walls){
            for (size_t row=0;row<rows_;row++)
                for (size_t col=0;col<cols_;col++)
                    data_[row * cols_ + col] = 0; 

            for (const auto& wall: walls)
                data_[cols_ * wall.row_ + wall.col_] = 1;
        }

        const int& operator()(const Location& location) const{
            if (location.row_ >= rows_ || location.col_ >= cols_)
                throw std::out_of_range("Location out of range");

            return data_[cols_ * location.row_ + location.col_];
        }

        size_t NumRows() const {return rows_;}
        size_t NumCols() const {return cols_;}

        
};

Locations FindPath(const Matrix& matrix, const Location& start, const Location& end){
    Locations path;
    //add your code here
    int m = matrix.NumRows();
    int n = matrix.NumCols();

    int start_r = start.row_;
    int start_c = start.col_;
    int depth = 0;
    //create a queue where each element is a tuple of (start_r, start_c, depth, prev_r, prev_c)

    std::queue<std::tuple<int, int, int, int, int>> q;
    q.push(std::make_tuple(start_r, start_c, 0, -1, -1));
    //create a visited dictionary with key as (start_r, start_c) and value as (prev_r, prev_c)
    std::map<std::tuple<unsigned int, unsigned int>, std::tuple<unsigned int, unsigned int>> visited;
    visited[std::make_tuple(start_r, start_c)] = std::make_tuple(-1, -1);
    //print queue

    while (!q.empty()){
        std::tuple<int, int, int, int, int> curr = q.front();
        unsigned int r, c, depth, prev_r, prev_c;
        std::tie(r, c, depth, prev_r, prev_c) = curr;

        if (r == end.row_ && c == end.col_){
            visited[std::make_tuple(r, c)] = std::make_tuple(prev_r, prev_c);
            break;
        }
    //     //check if r-1 and c location in the matrix is 0 and not visited
    //     if (r-1 >= 0 && matrix(Location{r-1, c}) == 0 && visited.find(std::make_tuple(r-1, c)) == visited.end()){
    //         q.push(std::make_tuple(r-1, c, depth+1, r, c));
    //     }

    //     //check if r+1 and c location in the matrix is 0 and not visited
    //     if (r+1 < m && matrix(Location{r+1, c}) == 0 && visited.find(std::make_tuple(r+1, c)) == visited.end()){
    //         q.push(std::make_tuple(r+1, c, depth+1, r, c));
    //     }

    //     //check if r and c-1 location in the matrix is 0 and not visited
    //     if (c-1 >= 0 && matrix(Location{r, c-1}) == 0 && visited.find(std::make_tuple(r, c-1)) == visited.end()){
    //         q.push(std::make_tuple(r, c-1, depth+1, r, c));
    //     }

    //     //check if r and c+1 location in the matrix is 0 and not visited
    //     if (c+1 < n && matrix(Location{r, c+1}) == 0 && visited.find(std::make_tuple(r, c+1)) == visited.end()){
    //         q.push(std::make_tuple(r, c+1, depth+1, r, c));
    //     }

        visited[std::make_tuple(r, c)] = std::make_tuple(prev_r, prev_c);

        //print visited dictionary
        for (auto it = visited.begin(); it != visited.end(); it++){
            std::cout << "(" << std::get<0>(it->first) << ", " << std::get<1>(it->first) << ") -> (" << std::get<0>(it->second) << ", " << std::get<1>(it->second) << ")" << std::endl;
        
    }

    // Location curr_node = end;
    // //create a path vector of Location
    // using rev_output = std::vector<Location>;
    
    // rev_output rev_path;

    // for (int i =0;i<= depth;i++){
    //     rev_path.push_back(curr_node);
        
    //     //if no path was found return empty path
    //     if (visited.find(std::make_tuple(curr_node.row_, curr_node.col_)) == visited.end()){
    //         return rev_path;
    //     }

    //     curr_node = Location{std::get<0>(visited[std::make_tuple(curr_node.row_, curr_node.col_)]), 
    //     std::get<1>(visited[std::make_tuple(curr_node.row_, curr_node.col_)])};
    // }

    // //reverse the path vector and return it
    // std::reverse(rev_path.begin(), rev_path.end());
    // return rev_path;    

    return Locations();
}


int main(){

    //create a matrix

    Locations walls = {Location{1, 1}, Location{1, 2}, Location{1, 3}, Location{1, 4}};

    Matrix matrix(10, 10, walls);

    //create a start location
    Location start{0, 0};
    //create an end location
    Location end{4, 4};

    //find the path
    Locations path = FindPath(matrix, start, end);

    //print the path
    for (const auto& location: path)
        std::cout << location.row_ << " " << location.col_ << std::endl;

    return 0;
}