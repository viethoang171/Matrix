/*******************************************************************************
 *				 _ _                                             _ _
                |   |                                           (_ _)
                |   |        _ _     _ _   _ _ _ _ _ _ _ _ _ _   _ _
                |   |       |   |   |   | |    _ _     _ _    | |   |
                |   |       |   |   |   | |   |   |   |   |   | |   |
                |   |       |   |   |   | |   |   |   |   |   | |   |
                |   |_ _ _  |   |_ _|   | |   |   |   |   |   | |   |
                |_ _ _ _ _| |_ _ _ _ _ _| |_ _|   |_ _|   |_ _| |_ _|
                                (C)2021 Lumi
 * Copyright (c) 2021
 * Lumi, JSC.
 * All Rights Reserved
 *
 * File name: Example.c
 *
 * Description: This code is used for tranning Lumi IOT member. It is the code form statandard.
 *
 * Author: PhuongNP
 *
 * Last Changed By:  $Author: phuongnp $
 * Revision:         $Revision: $
 * Last Changed:     $Date: $Jun 9, 2021
  ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdint.h>
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define MAX_N 100
typedef uint32_t u32_t;
typedef uint32_t *u32_p;
typedef void void_t;
/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/******************************************************************************
                           Function input mang 2 chieu
******************************************************************************/
void_t Input_Array(u32_t pdwBuffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function output mang 2 chieu
******************************************************************************/
void_t Output_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function kiem tra xem co phai so nguyen to khong?
******************************************************************************/
u32_t Check_Prime(u32_t prime);

/******************************************************************************
                           Function dem so luong so nguyen to trong mang 2 chieu
******************************************************************************/
u32_t Count_prime_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function printf yeu cau bai toan
******************************************************************************/
void_t Request();
/******************************************************************************
                           Ham Main
******************************************************************************/
void_t main()
{
    Request();
    u32_t dw_Buffer[MAX_N][MAX_N];
    u32_t dw_Row, dw_Column;
    Input_Array(dw_Buffer, &dw_Row, &dw_Column);
    Output_Array(dw_Buffer, &dw_Row, &dw_Column);
    u32_t Count_prime = Count_prime_Array(dw_Buffer, &dw_Row, &dw_Column);
    printf("\nSo luong so nguyen to trong mang 2 chieu la:  %d", Count_prime);
}

void_t Input_Array(u32_t pdwBuffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    // Input number of rows and check
    do
    {
        printf("\nNhap vao so dong: ");
        scanf("%d", pdw_Row);

        if (*pdw_Row < 1 || *pdw_Row > MAX_N)
        {
            printf("\nSo dong khong hop le. Xin kiem tra lai!");
        }

    } while (*pdw_Row < 1 || *pdw_Row > MAX_N);

    // Input number of columns and check
    do
    {
        printf("\nNhap vao so cot: ");
        scanf("%d", pdw_Column);

        if (*pdw_Column < 1 || *pdw_Column > MAX_N)
        {
            printf("\nSo cot khong hop le. Xin kiem tra lai!");
        }

    } while (*pdw_Column < 1 || *pdw_Column > MAX_N);
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            printf("\nNhap Buffer[%d][%d] = ", i, j);
            scanf("%d", &pdwBuffer[i][j]);
        }
    }
}

void_t Output_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            printf("%4d", pdw_Buffer[i][j]);
        }
        printf("\n\n");
    }
}

u32_t Check_Prime(u32_t dw_prime)
{
    if (dw_prime == 2) // Neu la so 2 thi chung to la so nguyen to luon
        return 1;
    u32_t dw_sqrt_prime = sqrt(dw_prime); // Lay can bac 2 cua so can kiem tra
    for (u32_t i = 2; i <= sqrt(dw_prime); i++)
        if (dw_prime % i == 0)
            return 1;
    return 0;
}

u32_t Count_prime_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_prime = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            if (Check_Prime(pdw_Buffer[i][j]) != 0)
            {
                dw_Count_prime++;
            }
        }
    }
    return dw_Count_prime;
}

void_t Request()
{
    printf("Tao 1 mang 2 chieu gom cac phan tu so nguyen khong dau\n");
    printf("Xuat ra man hinh mang 2 chieu vua tao\n");
    printf("Kiem tra mang 2 chieu co bao nhieu so nguyen to?\n");
    printf("Xuat ra man hinh so luong so nguyen to trong  mang");
}