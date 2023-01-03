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
typedef enum
{
    MONDAY = 2,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Day_on_week;
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
u32_t Check_Prime(u32_t dw_prime);

/******************************************************************************
                           Function dem so luong so nguyen to trong mang 2 chieu
******************************************************************************/
u32_t Count_prime_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function dem so luong so chinh phuong trong mang 2 chieu
******************************************************************************/

u32_t Count_perfect_square_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function dem so luong so hoan hao trong mang 2 chieu
******************************************************************************/
u32_t Count_perfect_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function dem so luong chan trong mang 2 chieu
******************************************************************************/

u32_t Count_even_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function dem so luong so le trong mang 2 chieu
******************************************************************************/

u32_t Count_odd_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function dem so luong so 0 trong mang 2 chieu
******************************************************************************/

u32_t Count_zero_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function dem so luong so 1 trong mang 2 chieu
******************************************************************************/

u32_t Count_one_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column);

/******************************************************************************
                           Function printf yeu cau bai toan
******************************************************************************/
void_t Request();
/******************************************************************************
                           Ham Main
******************************************************************************/
void_t main()
{
    u32_t dw_day;
    Request(&dw_day);
    u32_t dw_Buffer[MAX_N][MAX_N];
    u32_t dw_Row, dw_Column;
    Input_Array(dw_Buffer, &dw_Row, &dw_Column);
    Output_Array(dw_Buffer, &dw_Row, &dw_Column);
    u32_t dw_Result;
    switch (dw_day)
    {
    case MONDAY:
        dw_Result = Count_prime_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so nguyen to trong mang 2 chieu la:  %d", dw_Result);
        break;
    case TUESDAY:
        dw_Result = Count_perfect_square_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so chinh phuong trong mang 2 chieu la: %d", dw_Result);
        break;
    case WEDNESDAY:
        dw_Result = Count_perfect_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so hoan hao trong mang 2 chieu la: %d", dw_Result);
        break;
    case THURSDAY:
        dw_Result = Count_even_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so chan trong mang 2 chieu la: %d", dw_Result);
        break;
    case FRIDAY:
        dw_Result = Count_odd_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so le trong mang 2 chieu la: %d", dw_Result);
        break;
    case SATURDAY:
        dw_Result = Count_zero_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so 0 trong mang 2 chieu la: %d", dw_Result);
        break;
    case SUNDAY:
        dw_Result = Count_one_Array(dw_Buffer, &dw_Row, &dw_Column);
        printf("\nSo luong so 1 trong mang 2 chieu la: %d", dw_Result);
        break;
    }
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

void_t Request(u32_p pdw_day)
{
    printf("Tao 1 mang 2 chieu gom cac phan tu so nguyen khong dau\n");
    printf("Xuat ra man hinh mang 2 chieu vua tao\n");
    printf("Nhap so tu 2-8 tuong ung voi MONDAY-SUNDAY\n");
    printf("Nhap ngay: ");
    scanf("%d", pdw_day);
    printf("\n");
    switch (*pdw_day)
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

u32_t Count_perfect_square_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_perfect_square = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            u32_t dw_sqrt_perfect_square = sqrt(pdw_Buffer[i][j]);
            if (dw_sqrt_perfect_square * dw_sqrt_perfect_square == pdw_Buffer[i][j])
            {
                dw_Count_perfect_square++;
            }
        }
    }
    return dw_Count_perfect_square;
}

u32_t Count_perfect_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_perfect = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            u32_t dw_sum_divisor = 0;
            for (u32_t k = 1; k < pdw_Buffer[i][j]; k++)
            {
                if (pdw_Buffer[i][j] % k == 0)
                    dw_sum_divisor += pdw_Buffer[i][j];
            }
            if (dw_sum_divisor == pdw_Buffer[i][j]) // Kiem tra tong cac uoc cua so do cos bang so do khong?
                dw_Count_perfect++;
        }
    }
    return dw_Count_perfect++;
}

u32_t Count_even_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_even = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            if (pdw_Buffer[i][j] % 2 == 0)
                dw_Count_even++;
        }
    }
    return dw_Count_even;
}

u32_t Count_odd_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_odd = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            if (pdw_Buffer[i][j] % 2 != 0)
                dw_Count_odd++;
        }
    }
    return dw_Count_odd;
}

u32_t Count_zero_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_zero = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            if (pdw_Buffer[i][j] == 0)
                dw_Count_zero++;
        }
    }
    return dw_Count_zero;
}

u32_t Count_one_Array(u32_t pdw_Buffer[][MAX_N], u32_p pdw_Row, u32_p pdw_Column)
{
    u32_t dw_Count_one = 0;
    for (u32_t i = 0; i < *pdw_Row; i++)
    {
        for (u32_t j = 0; j < *pdw_Column; j++)
        {
            if (pdw_Buffer[i][j] == 1)
                dw_Count_one++;
        }
    }
    return dw_Count_one;
}