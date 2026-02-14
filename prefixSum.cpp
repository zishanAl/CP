// initialise a prefixsum mtrix
vector<vector<int>> prefixSum(n+1, vector<int>(m+1, 0));

// build pfs
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
        prefixSum[i][j] = matrix[i - 1][j - 1]
                     + prefixSum[i - 1][j]
                     + prefixSum[i][j - 1]
                     - prefixSum[i - 1][j - 1];
    }
}

int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;

int ans = prefixSum[x2][y2] - prefixSum[x1-1][y2] 
          - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1];
                  
cout<<ans<<endl;


// Submatrix Sum
// for (int r1 = 1; r1 <= R; ++r1) {
//     for (int r2 = r1; r2 <= R; ++r2) {
//         for (int c1 = 1; c1 <= C; ++c1) {
//             for (int c2 = c1; c2 <= C; ++c2) {
//                 long long sum = prefixSum[r2][c2]
//                               - prefixSum[r1 - 1][c2]
//                               - prefixSum[r2][c1 - 1]
//                               + prefixSum[r1 - 1][c1 - 1];
//                 // condition as per question
//             }
//         }
//     }
// }
