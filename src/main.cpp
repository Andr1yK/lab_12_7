#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

struct Elem
{
  Elem *link;
  int info;
};

void enqueue(Elem *&first, Elem *&last, int value)
{
  Elem *tmp = new Elem; // 1
  tmp->info = value;
  tmp->link = NULL; // 3
  if (last != NULL)
    last->link = tmp; // 4
  last = tmp;         // 5
  if (first == NULL)
    first = tmp; // 6
}

void ReadFromFile(Elem *&top, Elem *&last, char *fname)
{
  ifstream fromFile(fname);
  string str;

  int pos = -1;
  int posEnd = 0;
  int index = 0;
  int size = 0;
  int value = 0;

  string tempLine;

  getline(fromFile, str);
  size = str.size();

  do {
    posEnd = str.find(" ", pos + 1);
    if (posEnd == -1) {
      break;
    }

    value = stoi(tempLine.assign(str, pos + 1, posEnd - pos - 1));
    
    enqueue(top,last, value);

    pos = posEnd;
  } while (pos < size && pos != -1);

  fromFile.close();
}

void createSublist(Elem *&first, Elem *&sublist, Elem *&sublistEnd, int n, int k)
{
  Elem *L = first;
  Elem *temp = NULL;

  for (int i = 0; i < n; i++)
  {
    if (L->link != NULL)
    {
      L = L->link;
    }
    else
    {
      cout << "Invalid N (max index = " << i + 1 << ")" << endl;

      return;
    }
  }

  for (int i = n; i < n + k; i++)
  {
    if (L == NULL)
    {
      cout << "Invalid K (max index = " << i + 1 << ")" << endl;

      return;
    }

    enqueue(sublist, sublistEnd, L->info);

    L = L->link;
  }
}

void Print(Elem *first)
{
  while (first != NULL)
  {
    cout << first->info << "\t";
    first = first->link;
  }
  cout << endl;
}

int main()
{
  srand(time(NULL));
  int N, value, menu, n, k;
  char fname[] = "data.txt";
  Elem *first = NULL,
       *last = NULL;

  Elem *subfirst = NULL,
       *sublast = NULL;

  cout << "Input data (default) - 1 " << endl;
  cout << "Get data from file - 2 " << endl;

  cin >> menu;

  switch (menu)
  {
  case 2:
    ReadFromFile(first, last, fname);
    break;
  case 1:
  default:
    cout << "Count: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      cout << "Enter value: ";
      cin >> value;
      enqueue(first, last, value);
    }
    break;
  }

  cout << endl;

  cout << " N: ";
  cin >> n;
  cout << endl;
  cout << " K: ";
  cin >> k;


  cout << endl;
  cout << endl;

  Print(first);

  cout << endl;

  createSublist(first, subfirst, sublast, n, k);

  Print(subfirst);

  return 0;
}
