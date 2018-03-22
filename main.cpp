#include <iostream>
#include <cstring>

using namespace std;

struct MARSH {
    char from[20];
    char to[20];
    int id;
};

void print(MARSH a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Point of departure: " << a[i].from << endl;
        cout << "Arrival point: " << a[i].to << endl;
        cout << "ID: " << a[i].id << endl;
    }
}

void Sort(MARSH arr[], int n) {
    bool swapped = true;
    int j = 0;
    MARSH tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (arr[i].id > arr[i + 1].id) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}

int main()
{
    const int N = 3;
    MARSH a[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Input point of departure: "; cin >> a[i].from;
        cout << "Input arrival Point: "; cin >> a[i].to;
        cout << "Input num: "; cin >> a[i].id;
    }
    print(a, N);
    Sort(a, N);
    system("read _");
    system("clear");

    print(a, N);

    char input[20];
    bool finded = false;

    cout << "Input point: "; cin >> input;
    
    for (int i = 0; i < N; i++)
    {
        if (strcmp(a[i].from, input))
        {
            print(a, N);
            finded = true;
            continue;
        }

        if (strcmp(a[i].to, input))
        {
            print(a, N);
            finded = true;
            continue;
        }
    }

    if (!finded) cout << "Not finded" << endl;

    system("read _");
    return 0;
}