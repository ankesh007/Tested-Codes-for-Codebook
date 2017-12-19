void update(int x , int y , int val){
    while (x <= max_x){
        updatey(x , y , val); 
        // this function should update array tree[x] 
        x += (x & -x); 
    }
}
void updatey(int x , int y , int val){
    while (y <= max_y){
        tree[x][y] += val;
        y += (y & -y); 
    }
}
void update(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}

int getSum(int BIT[][N+1], int x, int y)
{
    int sum = 0;
 
    for(; x > 0; x -= x&-x)
    {
        // This loop sum through all the 1D BIT
        // inside the array of 1D BIT = BIT[x]
        for(; y > 0; y -= y&-y)
        {
            sum += BIT[x][y];
        }
    }
    return sum;
}
 