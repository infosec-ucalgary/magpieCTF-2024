﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Class4
    {
        public byte[] A = { 121, 68, 80, 23, 122, 231, 61, 48, 181, 174, 206, 216, 144, 247, 208, 224, 231, 165, 224, 81, 167, 108, 180, 89, 116, 63, 96, 238, 32, 212, 35, 200, 228, 207, 61, 198, 13, 211, 224, 105, 103, 54, 231, 217, 241, 148, 179, 113, 55, 78, 161, 94, 233, 161, 31, 47, 135, 106};
        public byte[] B = { 102, 133, 244, 203, 17, 247, 82, 3, 191, 232, 164, 135, 251, 140, 240, 176, 224, 206, 102, 230, 80, 170, 245, 160, 123, 52, 207, 201, 18, 174, 49, 151, 83, 50, 28, 28, 6, 232, 66, 72, 73, 105, 101, 233, 131, 193, 184, 59, 73, 135, 197, 213, 255, 100, 27, 7, 139, 6 };
        public byte[] C = { 241, 236, 79, 155, 190, 145, 71, 124, 181, 193, 70, 250, 106, 100, 182, 36, 202, 146, 198, 50, 157, 228, 201, 18, 55, 99, 56, 101, 4, 21, 227, 137, 146, 207, 89, 248, 216, 90, 14, 78, 138, 87, 44, 81, 93, 109, 21, 34, 66, 0, 191, 124, 34, 127, 38, 235, 114, 251 };

        public byte[] D = { 88, 255, 199, 211, 240, 86, 22, 115, 232, 5, 1, 46, 4, 118, 0, 91, 78, 130, 3, 155, 220, 79, 120, 204, 118, 67, 167, 103, 129, 133, 168, 176, 110, 43, 94, 156, 138, 227, 31, 9, 87, 192, 146, 132, 1, 27, 44, 103, 28, 145, 8, 152, 254, 16, 213, 71, 241, 218 };

        public byte[] E = { 73, 144, 18, 193, 72, 56, 153, 50, 171, 84, 35, 75, 225, 55, 56, 232, 83, 91, 143, 205, 138, 97, 159, 166, 118, 109, 88, 180, 39, 194, 230, 35, 13, 164, 87, 178, 50, 29, 55, 192, 31, 147, 104, 110, 107, 90, 161, 124, 131, 136, 27, 36, 144, 253, 200, 78, 180, 248 };


        public byte[] F()
        {
            return A.Concat(C).Concat(D).Concat(E).ToArray();
        }
    }
}