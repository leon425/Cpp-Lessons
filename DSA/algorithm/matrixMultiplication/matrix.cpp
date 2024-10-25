#include <iostream>
#include <vector>

// Regular Matrix Multiplication Algorithm
std::vector<std::vector<int>> mm(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2) {
    std::vector<std::vector<int>> m3;
    int row1 = m1.size(), col1 = m1[0].size();
    int row2 = m2.size(), col2 = m2[0].size();

    if (col1 != row2) {
        return m3;
    }

    // This resize works as well. Resizing both the rows and columns
    // m3.resize(row1, std::vector<int>(col2,0));
    // Resizing the m3 vector. Initializing each row with a second vector which has the size of col2 and the initial value of 0.

    m3.resize(row1);

    for (int k=0;k<row1;k++) {
        m3[k].resize(col2,0); // resize the m3[k] and initialize the value as 0.
        for (int i=0;i<col2;i++) { 
            for (int j=0;j<col1;j++) { // j < col1 || j < row2
                m3[k][i] += m1[k][j] * m2[j][i];
            }

        }
    }
    return m3;
}

int main() {
    // std::vector<std::vector<int>> matrix1 = 
    // {
    //     {0,3,5},
    //     {5,5,2}
    // };

    // std::vector<std::vector<int>> matrix2 = 
    // {
    //     {3,4},
    //     {3,-2},
    //     {4,-2}
    // };

    std::vector<std::vector<int>> matrix1 = 
    {
        {2,4,5,6},
        {3,4,5,6},
        {5,7,5,4},
        {5,7,6,4},
    };

    std::vector<std::vector<int>> matrix2 = 
    {
        {4,3,2,1},
        {5,7,4,5},
        {5,7,3,2},
        {6,7,2,2},
    };

    std::vector<std::vector<int>> result = mm(matrix1,matrix2);

    for (int i=0;i<result.size();i++) {
        for (int j=0;j<result[i].size();j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << '\n';
    }


    return 0;
}