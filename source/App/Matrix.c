/*******************************************************************************
 *				 _ _                                             _ _
                |   |                                           (_ _)
                |   |        _ _     _ _   _ _ _ _ _ _ _ _ _ _   _ _
                |   |       |   |   |   | |    _ _     _ _    | |   |
                |   |       |   |   |   | |   |   |   |   |   | |   |
                |   |       |   |   |   | |   |   |   |   |   | |   |
                |   |_ _ _  |   |_ _|   | |   |   |   |   |   | |   |
                |_ _ _ _ _| |_ _ _ _ _ _| |_ _|   |_ _|   |_ _| |_ _|
                                (C)2023 Lumi
 * Copyright (c) 2023
 * Lumi, JSC.
 * All Rights Reserved
 *
 * File name: Example.c
 *
 * Description: This code is used for tranning Lumi IOT member. It is the code form statandard.
 *
 * Author: HoangNV
 *
 * Last Changed By:  $Author: hoangnv $
 * Revision:         $Revision: $
 * Last Changed:     $Date: $Jan 3, 2023
  ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdint.h>
#include "typedefs.h"
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define MAX_N 100
typedef enum
{
    MONDAY = 2,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} DayOnWeek;
/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/******************************************************************************
                           Function input mang 2 chieu
******************************************************************************/
void_t inputArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function output mang 2 chieu
******************************************************************************/
void_t outputArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function kiem tra xem co phai so nguyen to khong?
******************************************************************************/
u32_t checkPrime(u32_t dwPrime);

/******************************************************************************
                           Function dem so luong so nguyen to trong mang 2 chieu
******************************************************************************/
u32_t countPrimeArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function dem so luong so chinh phuong trong mang 2 chieu
******************************************************************************/

u32_t countPerfectSquareArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function dem so luong so hoan hao trong mang 2 chieu
******************************************************************************/
u32_t countPerfectArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function dem so luong chan trong mang 2 chieu
******************************************************************************/

u32_t countEvenArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function dem so luong so le trong mang 2 chieu
******************************************************************************/

u32_t countOddArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function dem so luong so 0 trong mang 2 chieu
******************************************************************************/

u32_t countZeroArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function dem so luong so 1 trong mang 2 chieu
******************************************************************************/

u32_t countOneArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn);

/******************************************************************************
                           Function printf yeu cau bai toan
******************************************************************************/
void_t request(u32_p pdwDay);

/******************************************************************************
                           Ham Main
******************************************************************************/
void_t main()
{
    u32_t dwDay;
    request(&dwDay);
    u32_t dwBuffer[MAX_N][MAX_N];
    u32_t dwRow, dwColumn;
    inputArray(dwBuffer, &dwRow, &dwColumn);
    outputArray(dwBuffer, &dwRow, &dwColumn);
    u32_t dwResult;
    switch (dwDay)
    {
    case MONDAY:
        dwResult = countPrimeArray(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so nguyen to trong mang 2 chieu la:  %d", dwResult);
        break;
    case TUESDAY:
        dwResult = countPerfectSquareArray(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so chinh phuong trong mang 2 chieu la: %d", dwResult);
        break;
    case WEDNESDAY:
        dwResult = countPerfectArray(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so hoan hao trong mang 2 chieu la: %d", dwResult);
        break;
    case THURSDAY:
        dwResult = countEvenArray(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so chan trong mang 2 chieu la: %d", dwResult);
        break;
    case FRIDAY:
        dwResult = countOddArray(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so le trong mang 2 chieu la: %d", dwResult);
        break;
    case SATURDAY:
        dwResult = countZeroArray(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so 0 trong mang 2 chieu la: %d", dwResult);
        break;
    case SUNDAY:
        dwResult = Count_one_Array(dwBuffer, &dwRow, &dwColumn);
        printf("\nSo luong so 1 trong mang 2 chieu la: %d", dwResult);
        break;
    }
}

void_t inputArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    // Input number of rows and check
    do
    {
        printf("\nNhap vao so dong: ");
        scanf("%d", pdwRow);

        if (*pdwRow < 1 || *pdwRow > MAX_N)
        {
            printf("\nSo dong khong hop le. Xin kiem tra lai!");
        }

    } while (*pdwRow < 1 || *pdwRow > MAX_N);

    // Input number of columns and check
    do
    {
        printf("\nNhap vao so cot: ");
        scanf("%d", pdwColumn);

        if (*pdwColumn < 1 || *pdwColumn > MAX_N)
        {
            printf("\nSo cot khong hop le. Xin kiem tra lai!");
        }

    } while (*pdwColumn < 1 || *pdwColumn > MAX_N);
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            printf("\nNhap Buffer[%d][%d] = ", i, j);
            scanf("%d", &pdwBuffer[i][j]);
        }
    }
}

void_t outputArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            printf("%4d", pdwBuffer[i][j]);
        }
        printf("\n\n");
    }
}

u32_t checkPrime(u32_t dwPrime)
{
    if (dwPrime == 2) // Neu la so 2 thi chung to la so nguyen to luon
        return 1;
    u32_t dwSqrtPrime = sqrt(dwPrime); // Lay can bac 2 cua so can kiem tra
    for (u32_t i = 2; i <= sqrt(dwPrime); i++)
        if (dwPrime % i == 0)
            return 1;
    return 0;
}

u32_t countPrimeArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountPrime = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            if (checkPrime(pdwBuffer[i][j]) != 0)
            {
                dwCountPrime++;
            }
        }
    }
    return dwCountPrime;
}

void_t request(u32_p pdwDay)
{
    printf("Tao 1 mang 2 chieu gom cac phan tu so nguyen khong dau\n");
    printf("Xuat ra man hinh mang 2 chieu vua tao\n");
    printf("Nhap so tu 2-8 tuong ung voi MONDAY-SUNDAY\n");
    printf("Nhap ngay: ");
    scanf("%d", pdwDay);
    printf("\n");
    switch (*pdwDay)
    {
    case MONDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so nguyen to?\n");
        printf("Xuat ra man hinh so luong so nguyen to trong  mang");
        break;
    }
    case TUESDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so chinh phuong?\n");
        printf("Xuat ra man hinh so luong so chinh phuong trong  mang");
        break;
    }
    case WEDNESDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so hoan hao?\n");
        printf("Xuat ra man hinh so luong so hoan thien trong mang");
        break;
    }
    case THURSDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so chan?\n");
        printf("Xuat ra man hinh so luong so chan trong mang");
        break;
    }
    case FRIDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so le?\n");
        printf("Xuat ra man hinh so luong so le trong mang");
        break;
    }
    case SATURDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so 0?\n");
        printf("Xuat ra man hinh so luong so 0 trong mang");
        break;
    }
    case SUNDAY:
    {
        printf("Kiem tra mang 2 chieu co bao nhieu so 1?\n");
        printf("Xuat ra man hinh so luong so 1 trong mang");
        break;
    }
    }
}

u32_t countPerfectSquareArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountPerfectSquare = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            u32_t dwSqrtPerfectSquare = sqrt(pdwBuffer[i][j]);
            if (dwSqrtPerfectSquare * dwSqrtPerfectSquare == pdwBuffer[i][j])
            {
                dwCountPerfectSquare++;
            }
        }
    }
    return dwCountPerfectSquare;
}

u32_t countPerfectArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountPerfect = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            u32_t dwSumDivisor = 0;
            for (u32_t k = 1; k < pdwBuffer[i][j]; k++)
            {
                if (pdwBuffer[i][j] % k == 0)
                    dwSumDivisor += pdwBuffer[i][j];
            }
            if (dwSumDivisor == pdwBuffer[i][j]) // Kiem tra tong cac uoc cua so do co bang so do khong?
                dwCountPerfect++;
        }
    }
    return dwCountPerfect++;
}

u32_t countEvenArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountEven = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            if (pdwBuffer[i][j] % 2 == 0)
                dwCountEven++;
        }
    }
    return dwCountEven;
}

u32_t countOddArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountOdd = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            if (pdwBuffer[i][j] % 2 != 0)
                dwCountOdd++;
        }
    }
    return dwCountOdd;
}

u32_t countZeroArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountZero = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            if (pdwBuffer[i][j] == 0)
                dwCountZero++;
        }
    }
    return dwCountZero;
}

u32_t countOneArray(u32_t pdwBuffer[][MAX_N], u32_p pdwRow, u32_p pdwColumn)
{
    u32_t dwCountOne = 0;
    for (u32_t i = 0; i < *pdwRow; i++)
    {
        for (u32_t j = 0; j < *pdwColumn; j++)
        {
            if (pdwBuffer[i][j] == 1)
                dwCountOne++;
        }
    }
    return dwCountOne;
}