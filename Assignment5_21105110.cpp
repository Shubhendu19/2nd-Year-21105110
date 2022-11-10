#include <iostream>
usng namespace std;

void Bubble(int arr[], int n)
{
    int i = 0;
    int j = 1;
    int t = n - 1;
    int swaps = 0;
    int comparisons = 0;
    while (t > 0)
    {
        while (j <= t)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                swaps++;
            }
            i++;
            j++;
            comparisons++;
        }
        t--;
        i = 0, j = 1;
    }
    cout << " . Total number of swaps in bubble sort" << swaps << endl;
    cout << " . Total number of comparisons in bubble sort" << comparisons << endl;
}

int min_ind(int arr[], int s, int e)
{

    int m = arr[s];
    int min_ind = s;
    for (int i = s; i <= e; i++)
    {
        int min_prev = m;
        m = min(m, arr[i]);
        if (m < min_prev)
        {
            min_ind = i;
        }
    }
    return min_ind;
}

void Selection(int arr[], int n)
{

    int s = 0, e = n - 1;
    int swaps = 0;
    int comparisons = 0;
    while (s < e)
    {
        int mi = min_ind(arr, s, e);
        comparisons = comparisons + (e - s + 1);
        if (s != mi)
        {
            swap(arr[s], arr[mi]);
            swaps++;
        }
        s++;
    }
    cout << " . Total number of swaps in selection sort" << swaps << endl;
    cout << " . Total number of comparisons in bubble sort" << comparisons << endl;
}

void func(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n;

    cout << "Enter number of elements in array:";
    cin >> n;

    int arr1[n];
    int arr2[n];

    cout << "Enter elements:";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr1[i] = a;
        arr2[i] = a;
    }

    cout << "\n Array to be sorted";
    func(arr1, n);
    cout << endl;

    Bubble(arr1, n);
    cout << "Bubble Sort Result:";
    func(arr1, n);
    cout << endl;

    Selection(arr2, n);
    cout << "Selection Sort Result";
    func(arr2, n);
}

// BONUS QUESTION
// Time Complexity of:

// Bubble Sort:
// In the above Bubble Sort code the first while loop will run n-1
// times and second while loop will run n-2 times and will go till 1.
// Time Complexity=O(n(n-1)/2)
//                   =O(n^2)
// Selection Sort:
// In the above Selection Sort code the program will search for minimum element in n size array, then again for (n-1) size array and will go on till 1.
// Time Complexity=n(n+1)/2
//                    =O(n^2)
