#pragma once
#include <QRandomGenerator>
#include <QString>
#include <QDebug>
class game
{
    int points[6];
    int same_nums[2];
    bool isShunzi;
    int rank;
    int nums[7] = {0};
    int sum = 0;
    QString rank_name;

public:
    //掷骰子
    void dice()
    {
        for (int i = 0; i < 6; i++)
        {
            points[i] = QRandomGenerator ::global()->bounded(1, 7);
        }
    }
    //进行判断
    void judge()
    {
        for (int i = 1; i <= 6; i++)
        {
            nums[points[i]]++;
            sum += points[i];
        }

        isShunzi = true;
        for (int i = 1; i <= 6; i++)
        {
            if (nums[i] != 1)
            {
                isShunzi = false;
                break;
            }
        }

        for (int i = 1; i <= 6; i++)
        {
            if (same_nums[0] < nums[i])
            {
                same_nums[1] = i;
                same_nums[0] = nums[i];
            }
        }
    }

    //排等级
    int get_rank()
    {
        if (nums[4] == 4 && nums[1] == 2)
            rank = 120;
        else if (nums[4] == 6)
            rank = 110;
        else if (nums[1] == 6)
            rank = 100;
        else if (nums[6] == 6)
            rank = 98;
        else if (nums[5] == 6)
            rank = 96;
        else if (nums[3] == 6)
            rank = 94;
        else if (nums[2] == 6)
            rank = 92;
        else if (nums[4] == 5)
        {
            rank = 80;
            for (int i = 1; i <= 6; i++)
            {
                if (nums[i] == 1)
                {
                    rank += i;
                    break;
                }
            }
        }
        else if (same_nums[1] == 5)
            rank = 70;
        else if (nums[4] == 4)
            rank = 60;
        else if (isShunzi)
            rank = 50;
        else if (nums[4] == 3)
            rank = 40;
        else if (same_nums[1] == 4)
            rank = 30;
        else if (nums[4] == 2)
            rank = 20;
        else if (nums[4] == 1)
            rank = 10;
        else
            rank = 0;
            return rank;
    }

    QString get_rank_name()
    {
        if (rank == 120)
            rank_name = "金花";
        else if (rank == 110)
            rank_name = "六杯红";
        else if (rank == 100)
            rank_name = "遍地锦";
        else if (rank >= 90)
            rank_name = "六杯黑";
        else if (rank >= 80)
            rank_name = "五红";
        else if (rank >= 70)
            rank_name = "五子登科";
        else if (rank >= 60)
            rank_name = "四点红";
        else if (rank >= 50)
            rank_name = "对堂";
        else if (rank >= 40)
            rank_name = "三红";
        else if (rank >= 30)
            rank_name = "四进";
        else if (rank >= 20)
            rank_name = "二举";
        else if (rank >= 10)
            rank_name = "一秀";
        else
            rank_name = "没中奖";
            return rank_name;
    }
};
//更细节的评分
//     if (nums[4] == 4 && nums[1] == 2)
//         rank = 1200;
//     else if (nums[4] == 6)
//         rank = 1100;
//     else if (nums[1] == 6)
//         rank = 1000;
//     else if (nums[6] == 6)
//         rank = 980;
//     else if (nums[5] == 6)
//         rank = 960;
//     else if (nums[3] == 6)
//         rank = 940;
//     else if (nums[2] == 6)
//         rank = 920;
//     else if (nums[4] == 5)
//     {
//         rank = 800;
//         for (int i = 1; i <= 6; i++)
//         {
//             if (nums[i] == 1)
//             {
//                 rank += i*10;
//                 break;
//             }
//         }
//     }
//     else if (same_nums[1] == 5)
//     {
//         switch (same_nums[0])
//         {
//         case 6:
//             rank = 790+sum-30;
//             break;
//         case 5:
//             rank = 780+sum-25;
//             break;
//         case 3:
//             rank = 770+sum-15;
//             break;
//         case 2:
//             rank = 760+sum-10;
//             break;
//         case 1:
//             rank = 750+sum-5;
//             break;
//         }
//     }
//     else if(nums[4]==4)
//     {
//         rank=600+sum-16;
//     }
//     else if(isShunzi)
//     {
//         rank=500;
//     }
//     else if(nums[4]==3)
//     {
//         rank=400+sum-12;
//     }
//     else if(same_nums[1]==4)
//     {
//         switch (same_nums[0])
//         {
//         case 6:
//             rank = 390+sum-24;
//             break;
//         case 5:
//             rank = 380+sum-20;
//             break;
//         case 3:
//             rank = 370+sum-12;
//             break;
//         case 2:
//             rank = 360+sum-8;
//             break;
//         case 1:
//             rank = 350+sum-4;
//             break;
//         }
//     }
//     else if(nums[4]==2)
//     {
//         rank=200+sum-8;
//     }
//     else if(nums[4]==1)
//     {
//         rank=100+sum-4;
//     }
// }