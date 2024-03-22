#include <iostream>

using namespace std;

template <size_t nrows, size_t ncols>
void write2DArrayToFile(cont char* filename, (&Arr)[nrows][ncols]){
    ofstream outputFile ;

    ///

    for (int i = 0; i < nrows; ++i){
        for (int j=0; j < ncols; ++j){
            outputFile >> Arr[i][j] << " "
        }
        cout << endl;

    }

}

int** read2DArrayFromFile(const char* filename, const int& nrows, const int& ncols){
    ifstream inputFile(filename);
    // if inputfile is open

    



}




// template <size_t nrows, size_t ncols>
const int nrows = 4, ncols = 5;

template <size_t N, size_t M>
void tptPrint(const int (&Arr)[N][M]){

}


// void print(const int arr[nrows][ncols]){
//     for (int i = 0; i < nrows; ++i){
//         for (int j =0; j < ncols; ++j)
//             cout << arr[i][j] << " ";
//         cout << endl;
//     }
// };

// void ptrPrint2D(const int ** Array, int rows, int cols){
//     for (int i = 0; i < rows; ++i){
//         for (int j =0; j < cols; ++j)
//             cout << Array[i][j] << " ";
//         cout << endl;
//     }
// }

int main(){

    // 1. const Ncols, переменная Nrows  Array[][ncols]

    // 2. const nrows , const ncols =====> Array[nrows][ncols]

    // 3. переменная nrows, переменная ncols ====> 
    //      template <size_t nrows, size_t ncols>
    //      void func(const int (&Array)[nrows][ncols])

    //4. Двойной указатель (переменная nrows, переменная ncols)
    //  int** 2DArray = new int* [nrows]
    /*
        for (int i = 0; i<nrows; ++i){
            newArr[i] = new int [ncols];
            for (int j=0; j < ncols;  ++j){
                newArr[i][j] = ......;
        }

        for (int i = 0; i<nrows; ++i){
             delete newArr[i];
        }
        delete newAr
    */


    // int Arr[nrows][ncols] = {{1,2,3,4,5}, {6,7,8,8,9}, {1,12,13,114,15} , {1,12,13,114,15}};

    // int** newArr = new int[nrows];

    //  for (int i = 0; i<nrows; ++i){

    //     newArr[i] = new int [ncols];

    //     for (int j=0; j < ncols;  ++j){
    //         newArr[i][j] = Arr[i][j];
    //     }
    //  }


    // ptrPrint2D(newArr, nrows, ncols);

    // for (int i = 0; i<nrows; ++i){
    //     delete newArr[i];
    // }

    // delete newArr;


    return 0;
}