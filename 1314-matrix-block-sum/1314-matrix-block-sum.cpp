class Solution {
public:
    
    int row;
    int col;
    
    int isvalid(int i, int j, vector<vector<int>> &mat) {
        if(i < 0 || j < 0) return 0;
        if(i >= row) i = row - 1;
        if(j >= col) j = col - 1;
        return mat[i][j];
    } 
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        row = mat.size();
        col = mat[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                mat[i][j] = mat[i][j] + isvalid(i,j-1,mat) + isvalid(i-1,j,mat) - isvalid(i-1,j-1,mat); 
            }
        }
        vector<vector<int>>res(row, vector<int>(col,0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                res[i][j] = isvalid(i+k, j+k, mat) - isvalid(i-k-1, j+k, mat) - isvalid(i+k, j-k-1, mat) + isvalid(i-k-1, j-k-1, mat);
            }
        }
        return res;
    }
};