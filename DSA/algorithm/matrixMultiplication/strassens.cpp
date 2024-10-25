#include <iostream>
#include <vector>
#include <cmath>

// Without error handling if the matrix is invalid, e.g 
// 2 3 4
// 5 5
// 5 6

// Haven't had unpad algorithm

std::vector<int> sliceVector(const std::vector<int>& vec, int start, int end) {
    // Use the range constructor of std::vector to create a slice
    std::vector<int> result(vec.begin() + start, vec.begin() + end);
    return result;
}

std::vector<std::vector<int>> extractSubmatrix(const std::vector<std::vector<int>> vec, int size, int rowStart, int colStart) {
    std::vector<std::vector<int>> result;
    result.resize(size,std::vector<int>(size,0));

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            result[i][j] = vec[i + rowStart][j + colStart];
        }
    }
    return result;
}

std::vector<std::vector<int>> matrixAddition(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b) {  
    std::vector<std::vector<int>> result;
    result.resize(a.size(),std::vector<int>(a[0].size(),0));

    if (a.size() != b.size() && a[0].size() != b[0].size()) {
        return result;
    }
    
    for (int i=0;i<a.size();i++) {
        for (int j=0;j<a[0].size();j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

// Assume that the row and column are consistent. 
std::vector<std::vector<int>> matrixPadding(std::vector<std::vector<int>> vec) {
    
    if (vec.empty()) {
        return {};
    }
    int row = vec.size();
    int col = vec[0].size();
    int larger; 

    if (row > col) {
        larger = row;
    } else {
        larger = col;
    }
    
    int paddingTo = pow(2,ceil(log(larger)/log(2)));
    std::vector<std::vector<int>> result;
    result.resize(paddingTo,std::vector<int>(paddingTo,0));
    
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            result[i][j] = vec[i][j];
        }
        for (int j=0;j<paddingTo-col;j++) {
            result[i][j+col] = 0;
        }
    }
    for (int i=0;i<paddingTo-row;i++) {
        for (int j=0;j<paddingTo;j++) {
            result[i+row][j] = 0;
        }
    }
    return result;

}

// Calculate the n of the matrices if it's undefined in the function call
int matrixSize(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b) {
    int row1 = a.size();
    int col1 = a[0].size();
    int row2 = b.size();
    int col2 = b[0].size();
    int largest; 

    // Find the largest among all rows and columns. Can use heap, but I'm to lazy. It's 4 element anyway.
    if (row1 > col1 && row1 > row2 && row1 > col2) {
        largest = row1;
    } else if (col1 > row1 && col1 > row2 && col1 > col2) {
        largest = col1;
    } else if (row2 > col1 && row2 > row1 && row2 > col2) {
        largest = row2;
    } else {
        largest = col2;
    }
    int paddingTo = pow(2,ceil(log(largest)/log(2)));
    return paddingTo;
    
}

std::vector<std::vector<int>> mm(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int n = -1) {
    std::vector<std::vector<int>> c;
    c.resize(n,std::vector<int>(n,0));

    //if (a.size())
    
    if (n == -1) {
        n = matrixSize(a,b);
    }

    // Pad the Matrix
    a = matrixPadding(a);
    b = matrixPadding(b);

    // std::cout << "Matrix A \n";
    // for (int i=0;i<a.size();i++) {
    //     for (int j=0;j<a[i].size();j++) {
    //         std::cout << a[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }  
    // std::cout << '\n';
    // std::cout << '\n';

    // std::cout << "Matrix B \n";
    // for (int i=0;i<b.size();i++) {
    //     for (int j=0;j<b[i].size();j++) {
    //         std::cout << b[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }
    // std::cout << '\n';
    // std::cout << '\n';

    // Strassen's Formula
    

    // Apply the Formula, so that we get O(1)
    if (n <=2) {
        c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
        c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
        c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
        c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    } else {
        std::vector<std::vector<int>> a00 = extractSubmatrix(a,n/2,0,0);
        std::vector<std::vector<int>> a01 = extractSubmatrix(a,n/2,0,n/2);
        std::vector<std::vector<int>> a10 = extractSubmatrix(a,n/2,n/2,0);
        std::vector<std::vector<int>> a11 = extractSubmatrix(a,n/2,n/2,n/2);

        std::vector<std::vector<int>> b00 = extractSubmatrix(b,n/2,0,0);
        std::vector<std::vector<int>> b01 = extractSubmatrix(b,n/2,0,n/2);
        std::vector<std::vector<int>> b10 = extractSubmatrix(b,n/2,n/2,0);
        std::vector<std::vector<int>> b11 = extractSubmatrix(b,n/2,n/2,n/2);

        std::vector<std::vector<int>> c00 = matrixAddition(mm(a00,b00,n/2),mm(a01,b10,n/2));
        std::vector<std::vector<int>> c01 = matrixAddition(mm(a00,b01,n/2),mm(a01,b11,n/2));
        std::vector<std::vector<int>> c10 = matrixAddition(mm(a10,b00,n/2),mm(a11,b10,n/2));
        std::vector<std::vector<int>> c11 = matrixAddition(mm(a10,b01,n/2),mm(a11,b11,n/2));

        // Merge The matrix
        for (int i=0;i<n/2;i++) {
            for (int j=0;j<n/2;j++) {
                c[i][j] = c00[i][j];
                c[i][j+n/2] = c01[i][j];
                c[i+n/2][j] = c10[i][j];
                c[i+n/2][j+n/2] = c11[i][j];
            }
        }
    }
    return c;
}

int main() {
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

    std::vector<std::vector<int>> matrix3 = 
    {
        {4,3,2},
        {5,7,4},
        {5,7,3}
    };

    std::vector<std::vector<int>> matrix4 = 
    {
        {4,3},
        {5,7},
        {5,7}
    };

    //std::vector<std::vector<int>> result = mm(matrix1,matrix2,4);
    std::vector<std::vector<int>> result = mm(matrix3,matrix4,4);

    for (int i=0;i<result.size();i++) {
        for (int j=0;j<result[i].size();j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}