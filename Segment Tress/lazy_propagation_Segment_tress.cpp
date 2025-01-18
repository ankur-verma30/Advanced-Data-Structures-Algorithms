#include <bits/stdc++.h>

using namespace std;

class SegmentTrees
{

public:
    vector<int> segments, lazy;
    SegmentTrees(int n)
    {
        segments.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void build(int index, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            segments[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        segments[index] = segments[2 * index + 1] + segments[2 * index + 2];
    }

    void update(int index, int low, int high, int l, int r, int val)
    {
        if (lazy[index] != 0)
        {
            segments[index] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            lazy[index] = 0;
        }

        // no overlap
        if (high < l || r < low)
            return;

        // complete overlap
        if (high <= r && low >= l)
        {
            segments[index] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }
        // partial overlap
        int mid = (low + high) / 2;
        update(2 * index + 1, low, mid, l, r, val);
        update(2 * index + 2, mid + 1, high, l, r, val);
        segments[index] = segments[2 * index + 1] + segments[2 * index + 2];
    }

    int query(int index, int low, int high, int l, int r)
    {
        if (lazy[index] != 0)
        {
            segments[index] += (high - low + 1) * lazy[index];
            if (low != high)
            {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // no overlap
        if (high < l || r < low)
            return 0;

        // complete overlap
        if (high <= r && low >= l)
            return segments[index];

        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);

        return left + right;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTrees st(n);
    st.build(0, 0, n - 1, arr);
    cout << "First element of segment " << st.segments[0] << endl;
    int query;
    cout << "Number of queries ";
    cin >> query;
    while (query--)
    {
        int type;
        cin >> type;
        int l, r;
        cout << "Enter the range of (l,r): ";
        cin >> l >> r;
        if (type == 2)
        {
            int  val;
            cout << "Enter the index and value to update: ";
            cin >> val;
            st.update(0, 0, n - 1, l, r, val);
        }
        else if (type == 1)
        {
            cout << "Sum in range [" << l << ", " << r << "] is: " << st.query(0, 0, n - 1, l, r) << endl;
        }
    }
}