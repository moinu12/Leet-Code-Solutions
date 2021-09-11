
class Solution
{
public:
    struct Node
    {
        int V;
        int ind;
    };

    vector<int> tree, res ;

    Node N[100005];

    static bool cmp(Node n1, Node n2)
    {
        if (n1.V == n2.V)
            return n1.ind < n2.ind;
        else
            return n1.V < n2.V;

    }

    void update( int node, int b, int e, int indx )
    {
        if (indx < b || e <indx)
            return ;
        if (b <= indx && indx <= e )
            tree[node]++;

        if (b == e )
            return;

        int mid = ( b+e ) >> 1;
        update(node << 1, b, mid, indx);
        update( (node << 1 ) + 1, mid + 1, e, indx);


    }


    int query(int node, int b, int e, int i, int j)
    {
        if (i > e ||  j < b )
            return 0;

        if (i <= b && j >= e )
            return tree[node];

        int mid =(b+e) >> 1;

        int ret = 0;
        ret = ret + query(  node<<1, b, mid, i, j);
        ret = ret + query( (node<<1) + 1, mid + 1, e, i, j);
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums)
    {
        for (int i = 1; i<=nums.size(); i++)
        {
            N[i].V = nums[i-1];
            N[i].ind = i;
        }

        sort(&N[1], &N[nums.size() + 1], cmp);

        tree.resize(100005*4, 0 ) ;
        res.resize(nums.size(), 0);

        for (int i = 1; i<=nums.size(); i++)
        {

            res[N[i].ind - 1] = query(1, 1, nums.size(), N[i].ind, nums.size());
            update(1, 1, nums.size(), N[i].ind);
        }

        return res;

    }
};
