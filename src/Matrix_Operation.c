#include<stdio.h>
#include<stdlib.h>
#include"Matrix_Operation.h"

/*******************************************************************************
 * name   : Init_new_matrix
 * type   : void
 * arg    : int     num_of_row
              ...任意の行要素数.
            int     num_of_col
              ...任意の列要素数.
            double**  matrix_name
              ...任意の名前の"double**".
 * return : void
 * note   : この関数は与えられた行x列の要素数の二次元配列を確保する.
 * cation : この関数で配列を確保したら必ず,unformat_matrixで開放すること.
            -2147483647は配列の終端コード二なっているので使用しないこと,
            使いたかったら終端コードを変えること.
*******************************************************************************/
double** Init_new_matrix(int num_of_row, int num_of_col){
  int i,j;
  double** matrix_name;
  /*列要素の確保*/
  matrix_name = (double**)malloc(sizeof(double*)*(num_of_col + 1));

  /*各列ごとの行要素の確保*/
  for(int i = 0; i < (num_of_col + 1); i++){
    matrix_name[i] = (double*)malloc(sizeof(double)*(num_of_row + 1));
  }

  /* 初期化値終端値の代入 */
  for(i = 0; i < num_of_col; i++){
    for(j = 0; j < num_of_row; j++) matrix_name[i][j] = 0.0;
    matrix_name[i][j] = END_ARY;
  }
  matrix_name[i][0] = END_ARY;
  return matrix_name;
}



/*******************************************************************************
 * name   : check_matrix
 * arg    : double**    matrix1
                          ...任意の"double**".
            double**    matrix2
                          ...任意の"double**".
 * return : true or false
 * note   : この関数は与えられた二つの二次元配列の要素数が同じであるか調べる.
 * cation : 内積用のチェック関数は別.
 ******************************************************************************/
int check_matrix(double** matrix1, double** matrix2){

    int element_count1[2],element_count2[2];
    int i,j;

    /***** 行要素の要素数 *****/
    for(i = 0; matrix1[i][0] != END_ARY; i++) element_count1[0] = i;
    for(j = 0; matrix2[j][0] != END_ARY; j++) element_count2[0] = j;

    printf("i:%d\n",element_count1[0]);
    printf("j:%d\n\n\n",element_count2[0]);

    /***** 列要素の要素数 *****/
    for(i = 0; matrix1[0][i] != END_ARY; i++) element_count1[1] = i;
    for(j = 0; matrix2[0][j] != END_ARY; j++) element_count2[1] = j;


    printf("i:%d\n",element_count1[1]);
    printf("j:%d\n\n\n",element_count2[1]);

    /***** 各要素数同士のチェック *****/

    //真の場合
    if((element_count1[0] == element_count2[0]) &&
       (element_count1[1] == element_count2[1]))  return TRUE;

    //偽の場合
    else return FALSE;

}



/*******************************************************************************
 * name   : check_matrix_dot
 * arg    : double**    matrix1
                          ...任意の"double**".
            double**    matrix2
                          ...任意の"double**".
 * return : true or false
 * note   : この関数は与えられた二つの二次元配列の要素数が内積の定義を満たすか
            を確認する関数..
 * cation :
 ******************************************************************************/
int check_matrix_dot(double** matrix1, double** matrix2){

    int element_count1[2],element_count2[2];
    int i,j;

    /***** 行要素の要素数 *****/
    for(i = 0; matrix1[i][0] != END_ARY; i++) element_count1[0] = i;
    for(j = 0; matrix2[j][0] != END_ARY; j++) element_count2[0] = j;

    printf("i:%d\n",element_count1[0]);
    printf("j:%d\n\n\n",element_count2[0]);

    /***** 列要素の要素数 *****/
    for(i = 0; matrix1[0][i] != END_ARY; i++) element_count1[1] = i;
    for(j = 0; matrix2[0][j] != END_ARY; j++) element_count2[1] = j;


    printf("i:%d\n",element_count1[1]);
    printf("j:%d\n\n\n",element_count2[1]);

    /***** 各要素数同士のチェック *****/

    //真の場合
    if((element_count1[0] == element_count2[1]) &&
       (element_count1[1] == element_count2[0]))  return TRUE;

    //偽の場合
    else return FALSE;

}



/*******************************************************************************
 * name   : get_matrix_row
  * arg    : double**    matrix
                          ...任意の"double**".
 * return : 行要素数
 * note   : この関数は与えられた行列の行の要素数を求める.
 * cation :
******************************************************************************/
int get_matrix_row(double** matrix){
  int row;
  for(row = 0; matrix[0][row] != END_ARY; row++);
  return row;
}



/*******************************************************************************
 * name   : get_matrix_col
  * arg    : double**    matrix
                          ...任意の"double**".
 * return : 列要素数
 * note   : この関数は与えられた行列の列の要素数を求める.
 * cation :
******************************************************************************/
int get_matrix_col(double** matrix){
  int col;
  for(col = 0; matrix[col][0] != END_ARY; col++);
  return col;
}



/*******************************************************************************
 * name   : add_matrix
  * arg    : double**    matrix1
                          ...任意の加算したい"double**".
            double**    matrix2
                          ...任意の加算したい"double**".
 * return : true or false
 * note   : この関数は与えられた二つの行列を加算しそのポインタを返す.
 * cation :
******************************************************************************/
/*double** add_matrix(double** matrix1, double** matrix2){

  double** added_matrix = NULL;

  for(int i = 0; matrix1[i][0] != END_ARY; i++){
    for(int j = 0; matrix1[i][j] != END_ARY; j++){
      added_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return added_matrix;
}*/



/*******************************************************************************
 * name   : sub_matrix
  * arg    : double**    matrix1
                          ...任意の減算したい"double**".
            double**    matrix2
                          ...任意の減算したい"double**".
 * return : true or false
 * note   : この関数は与えられた二つの行列を減算しそのポインタを返す.
 * cation :
******************************************************************************/
/*double** sub_matrix(double** matrix1, double** matrix2){

  double** subed_matrix = NULL;

  for(int i = 0; matrix1[i][0] != END_ARY; i++){
    for(int j = 0; matrix1[i][j] != END_ARY; j++){
      subed_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return subed_matrix;
}*/






/*************************************
 ******      テスト用メイン     ******
*************************************/
int main(){

  double** a = NULL;
  double** e = NULL;
  double** add = NULL;

  int c=3,b =2;

  a = Init_new_matrix(b, c);
  e = Init_new_matrix(b, c);
  add = Init_new_matrix(b,c);

  getchar();
}
