using System;
using System.Collections.Generic;

class solutions
{
    /*
     * Complete the 'commonSubstring' function below.
     *
     * The function accepts following parameters:
     *  1. STRING_ARRAY a
     *  2. STRING_ARRAY b
     *
     * Duas strings compartilham uma substring comum se e somente se
     * compartilham ao menos um caractere (pois um único caractere já
     * é uma substring válida).
     */
    public static void commonSubstring(List<string> a, List<string> b)
    {
        for (int i = 0; i < a.Count; i++)
        {
            Console.WriteLine(HasCommonCharacter(a[i], b[i]) ? "YES" : "NO");
        }
    }

    private static bool HasCommonCharacter(string s1, string s2)
    {
        // ascii[a-z] → 26 letras
        bool[] seen = new bool[26];

        foreach (char c in s1)
        {
            seen[c - 'a'] = true;
        }

        foreach (char c in s2)
        {
            if (seen[c - 'a'])
            {
                return true;
            }
        }

        return false;
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        int aCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<string> a = new List<string>();

        for (int i = 0; i < aCount; i++)
        {
            string aItem = Console.ReadLine();
            a.Add(aItem);
        }

        int bCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<string> b = new List<string>();

        for (int i = 0; i < bCount; i++)
        {
            string bItem = Console.ReadLine();
            b.Add(bItem);
        }

        solutions.commonSubstring(a, b);
    }
}
