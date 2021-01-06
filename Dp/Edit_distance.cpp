class Solution {
public:
    int minDistance(string word1, string word2) {
        int ax[word1.size()+1][word2.size()+1];
        for(int i=0;i<word1.size()+1;i++){
            for(int j=0;j<word2.size()+1;j++){
                if(i == 0){
                    ax[i][j] = j;
                }
                if(j == 0){
                    ax[i][j] = i;
                }
            }
        }
        for(int i=1;i<word1.size()+1;i++){
            for(int j=1;j<word2.size()+1;j++){
                if(word1[i-1] == word2[j-1]){
                    ax[i][j] = ax[i-1][j-1];
                }else{
                    ax[i][j] = 1+min(ax[i-1][j],min(ax[i][j-1],ax[i-1][j-1]));
                }
            }
        }
        return ax[word1.size()][word2.size()];
    }
};
