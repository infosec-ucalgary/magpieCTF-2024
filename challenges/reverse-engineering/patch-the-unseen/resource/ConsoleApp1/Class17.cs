﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Class17
    {
        public byte[] A = { 22, 183, 222, 28, 164, 215, 126, 151, 200, 190, 190, 151, 183, 4, 75, 38, 89, 76, 26, 247, 114, 149, 93, 11, 6, 149, 176, 24, 169, 201, 13, 19, 80, 185, 124, 141, 176, 98, 190, 3, 189, 91, 25, 240, 145, 15, 61, 178, 141, 198, 146, 35, 208, 31, 62, 221, 75 };

        public byte[] B = { 204, 47, 124, 108, 226, 210, 195, 117, 55, 31, 210, 240, 92, 219, 79, 170, 176, 85, 121, 89, 198, 31, 169, 166, 131, 183, 39, 15, 79, 12, 205, 239, 5, 218, 132, 169, 125, 251, 89, 146, 232, 116, 7, 194, 248, 177, 101, 15, 66, 146, 116, 238, 96, 9, 207, 16, 20 };
        public byte[] C = { 90, 217, 124, 27, 2, 102, 54, 181, 5, 204, 47, 36, 128, 134, 194, 245, 113, 24, 65, 203, 1, 188, 209, 239, 51, 81, 73, 80, 0, 151, 75, 225, 36, 253, 37, 44, 253, 8, 19, 107, 182, 254, 150, 239, 125, 21, 103, 103, 225, 49, 71, 159, 25, 230, 255, 79, 95, 227 };
        public byte[] D = { 109, 64, 167, 171, 153, 58, 207, 162, 229, 39, 91, 96, 34, 157, 184, 11, 227, 221, 246, 106, 47, 76, 137, 153, 182, 16, 228, 104, 91, 108, 110, 64, 139, 125, 59, 213, 157, 29, 53, 230, 49, 3, 14, 181, 175, 223, 149, 56, 224, 53, 19, 83, 191, 111, 12, 138, 21 };

        public byte[] E = { 127, 253, 5, 137, 117, 194, 221, 126, 210, 69, 95, 32, 32, 100, 189, 0, 193, 33, 191, 225, 105, 121, 172, 34, 25, 239, 85, 52, 50, 133, 219, 150, 179, 103, 244, 119, 110, 128, 255, 57, 218, 231, 187, 36, 199, 35, 250, 187, 126, 65, 27, 1, 61, 128, 9, 51, 113 };



        public byte[] F()
        {
            return A.Concat(B).Concat(D).Concat(E).ToArray();
        }
    }
}
