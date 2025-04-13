#include <bits/stdc++.h>
using namespace std;

class Item
{
    public:
    int value;
    int weight;
    float ratio;

    bool operator<(Item i)
    {
        return ratio > i.ratio;
    }

    Item()
    {
        value = 0;
        weight = 0;
        ratio = 0;
    }

    Item(int v, int w)
    {
        value = v;
        weight = w;
        ratio = (float)v / w;
    }
};

void print(vector<Item>items)
{
    cout << "Value\tWeight\tRatio\n";
    for(int i=0;i<items.size();i++)
    {
        cout << items[i].value << "\t" << items[i].weight << "\t" << items[i].ratio << endl;
    }
}

int Fractional_Knapsack(int n, int w, vector<Item>&items)
{
    sort(items.begin(), items.end());
    for(int i=0;i<items.size();i++)
    {
        if(w>items[i].weight)
        {
            w -= items[i].weight;
            items[i].weight = 0;
        }
        else
        {
            items[i].weight -= w;
            w = 0;
        }
    }
}
int NonFractional_Knapsack(int n, int w, vector<Item>& items)
{
    if (n == 0 || w == 0)
        return 0;

    if (items[n-1].weight > w)
        return NonFractional_Knapsack(n-1, w, items);

    else
        return max(items[n-1].value + NonFractional_Knapsack(n-1, w - items[n-1].weight, items),
                   NonFractional_Knapsack(n-1, w, items));
}
int main()
{
    int n, w;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter size of knapsack (w): ";
    cin >> w;

    vector<Item>items;

    for(int i=0;i<n;i++)
    {
        int v, w;
        cout << "Enter value and weight of item " << i+1 << ": ";
        cin >> v >> w;
        items.push_back(Item(v, w));
    }
}
