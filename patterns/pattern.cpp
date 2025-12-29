#include <bits/stdc++.h>

using namespace std;

void printPattern1(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void printPattern2(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}

void printPattern3(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << j + 1 << " ";
    }
    cout << endl;
  }
}

void printPattern4(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << i + 1 << " ";
    }
    cout << endl;
  }
}

void printPattern5(int n) {
  for (int i = n; i > 0; i--) {
    for (int j = i; j > 0; j--) {
      cout << "* ";
    }
    cout << endl;
  }
}

void printPattern6(int n) {
  for (int i = n; i > 0; i--) {
    for (int j = i; j > 0; j--) {
      cout << n - j + 1 << " ";
    }
    cout << endl;
  }
}

void printPattern7(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - i - 1); j++) {
      cout << " ";
    }
    for (int k = 0; k < (2 * i + 1); k++) {
      cout << "*";
    }
    cout << endl;
  }
}

void printPattern8(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << " ";
    }
    for (int k = 0; k < (2 * (n - i) - 1); k++) {
      cout << "*";
    }
    cout << endl;
  }
}

void printPattern9(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - i - 1); j++) {
      cout << " ";
    }

    for (int k = 0; k < (2 * i + 1); k++) {
      cout << "*";
    }

    cout << endl;
  }

  // lower triangle
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < i; k++) {
      cout << " ";
    }

    for (int j = 0; j < 2 * (n - i) - 1; j++) {
      cout << "*";
    }

    cout << endl;
  }
}

void printPattern10(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = n - 1; i > 0; i--) {
    for (int k = 0; k < i; k++) {
      cout << "*";
    }
    cout << endl;
  }
}

void printPattern11(int n) {
  int numberToPrint = 1;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= i; k++) {
      cout << numberToPrint;
      numberToPrint == 1 ? numberToPrint = 0 : numberToPrint = 1;
    }
    cout << endl;
  }
}

void printPattern12(int n) {
  for (int i = 0; i < n; i++) {
    int numberToPrint = 1;
    for (int k = 0; k < i + 1; k++) {
      cout << numberToPrint++;
    }

    for (int j = 0; j < 2 * (n - i - 1); j++) {
      cout << " ";
    }

    --numberToPrint;
    for (int k = 0; k < i + 1; k++) {
      cout << numberToPrint--;
    }
    cout << endl;
  }
}

void printPattern13(int n) {
  int numberToPrint = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << numberToPrint++ << " ";
    }
    cout << endl;
  }
}

void printPattern14(int n) {
  for (int i = 0; i < n; i++) {
    char characterToPrint = 'A';
    for (int j = 0; j <= i; j++) {
      cout << characterToPrint++;
    }
    cout << endl;
  }
}

void printPattern15(int n) {
  for (int i = 0; i < n; i++) {
    char characterToPrint = 'A';
    for (int j = 0; j < n - i; j++) {
      cout << characterToPrint++;
    }
    cout << endl;
  }
}

void printPattern16(int n) {
  char characterToPrint = 'A';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << characterToPrint;
    }
    characterToPrint++;
    cout << endl;
  }
}

void printPattern17(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }

    char characterToPrint = 'A';
    for (int k = 0; k < 2 * i + 1; k++) {
      cout << characterToPrint;
      if (k < i) {
        characterToPrint++;
      } else {
        characterToPrint--;
      }
    }

    cout << endl;
  }
}

void printPattern18(int n) {
  char finalCharacter = static_cast<char>(65 + (n - 1));

  for (int i = 0; i < n; i++) {
    char characterToPrint = static_cast<char>(finalCharacter - i);

    for (int j = 0; j <= i; j++) {
      cout << characterToPrint++;
    }
    cout << endl;
  }
}

void printPattern19(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << "*";
    }

    for (int k = 0; k < 2 * i; k++) {
      cout << " ";
    }

    for (int j = 0; j < n - i; j++) {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }

    for (int k = 0; k < 2 * (n - i - 1); k++) {
      cout << " ";
    }

    for (int j = 0; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void printPattern20(int n) {
  int initialSpace1 = 2 * n - 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }

    for (int k = 0; k < initialSpace1; k++) {
      cout << " ";
    }

    for (int j = 0; j <= i; j++) {
      cout << "*";
    }

    cout << endl;
    initialSpace1 -= 2;
  }

  int initialSpace2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << "*";
    }

    for (int k = 0; k < initialSpace2; k++) {
      cout << " ";
    }

    for (int j = 0; j < n - i; j++) {
      cout << "*";
    }
    cout << endl;
    initialSpace2 += 2;
  }
}

void printPattern21(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0 || j == n - 1 || i == 0 || i == n - 1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void printPattern22(int n) {
  // distance from top -> i
  // distance from bottom -> 2n - 2 - i
  // distance from left -> j
  // distance from right -> 2n - 2 - j

  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int topDistance = i;
      int leftDistance = j;
      int bottomDistance = 2 * n - 2 - i;
      int rightDistance = 2 * n - 2 - j;

      int currentValue =
          min({topDistance, bottomDistance, leftDistance, rightDistance});

      int numberToPrint = n - currentValue;
      cout << numberToPrint << ' ';
    }
    cout << endl;
  }
}

int main() {
  int n;

  for (int i = 0; i <= 2; i++) {
    cin >> n;
    printPattern22(n);
    cout << endl;
  }

  return 0;
}