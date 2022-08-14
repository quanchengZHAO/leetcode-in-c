
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);

int main(){

}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int maximumWealth = 0;
    for(int i = 0; i < accountsSize; i++) {
        int wealth = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            wealth += accounts[i][j];
        }
        if (wealth > maximumWealth) {
            maximumWealth = wealth;
        }
    }
    return maximumWealth;
}