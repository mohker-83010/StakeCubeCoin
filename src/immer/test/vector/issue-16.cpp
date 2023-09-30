//
// immer: immutable data structures for C++
// Copyright (C) 2016, 2017, 2018 Juan Pedro Bolivar Puente
//
// This software is distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt
//

// Thanks Dominic Chen <ddchen@cs.cmu.edu> for reporting this issue
// https://github.com/arximboldi/immer/issues/16

#include <immer/flex_vector.hpp>
#include <immer/flex_vector_transient.hpp>
#include <immer/heap/gc_heap.hpp>
#include <vector>

std::vector<unsigned> init = {
    291,  438, 755,  608, 594,  912,  73,   97,   496,  101,  837,  696,  978,
    948,  126, 131,  624, 26,   590,  201,  219,  339,  193,  218,  866,  407,
    538,  780, 312,  909, 129,  883,  571,  865,  854,  372,  488,  695,  750,
    341,  798, 375,  350, 1013, 361,  1012, 743,  425,  68,   280,  245,  149,
    342,  535, 901,  223, 285,  928,  666,  534,  166,  963,  171,  893,  297,
    1017, 549, 172,  505, 965,  831,  563,  79,   180,  147,  543,  639,  1022,
    880,  559, 426,  27,  657,  33,   252,  758,  8,    641,  699,  399,  335,
    473,  625, 703,  264, 796,  61,   737,  527,  795,  123,  200,  287,  857,
    208,  897, 354,  885, 581,  57,   752,  855,  56,   1007, 357,  643,  476,
    113,  955, 349,  299, 76,   393,  557,  967,  995,  233,  990,  469,  742,
    681,  874, 673,  530, 835,  24,   178,  81,   69,   40,   368,  981,  941,
    645,  808, 511,  982, 888,  136,  100,  960,  804,  806,  600,  500,  337,
    580,  551, 593,  612, 318,  660,  232,  17,   879,  86,   424,  202,  112,
    235,  791, 873,  838, 47,   574,  858,  78,   237,  846,  340,  802,  907,
    72,   38,  44,   902, 595,  940,  182,  784,  207,  355,  815,  545,  555,
    258,  144, 564,  463, 198,  1004, 4,    175,  468,  658,  59,   938,  63,
    20,   179, 714,  721, 723,  381,  3,    745,  415,  119,  413,  923,  157,
    824,  668, 409,  459, 560,  353,  379,  450,  430,  479,  274,  309,  661,
    508,  474, 771,  504, 674,  51,   173,  670,  83,   921,  1019, 956,  725,
    556,  427, 597,  794, 918,  95,   514,  98,   638,  205,  727,  162,  905,
    728,  431, 203,  828, 971,  648,  871,  215,  646,  1006, 816,  277,  861,
    576,  99,  637,  67,  28,   161,  137,  14,   506,  717,  93,   298,  251,
    975,  927, 818,  43,  284,  994,  196,  195,  260,  705,  604,  169,  296,
    785,  911, 398,  687, 760,  486,  642,  417,  445,  925,  763,  756,  653,
    662,  359, 84,   151, 980,  914,  440,  546,  329,  665,  435,  732,  922,
    377,  105, 532,  282, 822,  878,  419,  659,  65,   111,  421,  672,  146,
    320,  316, 31,   522, 145,  513,  373,  773,  184,  974,  621,  366,  124,
    623,  953, 267,  712, 121,  512,  214,  1002, 455,  694,  834,  618,  324,
    656,  257, 206,  554, 334,  606,  305,  1008, 190,  160,  502,  1024, 891,
    751,  789, 821,  462, 489,  908,  370,  164,  746,  270,  319,  491,  443,
    531,  775, 977,  244, 485,  840,  892,  850,  347,  729,  317,  74,   731,
    738,  790, 988,  903, 176,  211,  890,  509,  592,  444,  307,  45,   810,
    390,  239, 678,  999, 414,  693,  345,  363,  382,  602,  516,  801,  310,
    754,  774, 364,  480, 290,  322,  887,  168,  37,   140,  937,  578,  1005,
    614,  734, 449,  230, 541,  761,  931,  882,  920,  210,  807,  115,  964,
    521,  862, 628,  747, 490,  422,  788,  691,  675,  652,  25,   582,  585,
    961,  472, 722,  7,   367,  15,   275,  700,  249,  116,  969,  325,  706,
    493,  524, 537,  875, 22,   688,  843,  575,  288,  141,  830,  698,  562,
    833,  143, 117,  683, 1000, 238,  397,  827,  619,  686,  1018, 973,  80,
    689,  165, 702,  88,  332,  192,  730,  847,  408,  58,   634,  471,  958,
    204,  236, 314,  494, 158,  412,  226,  135,  103,  998,  85,   904,  587,
    194,  6,   380,  987, 266,  853,  369,  949,  34,   799,  884,  16,   944,
    701,  313, 300,  611, 148,  457,  216,  900,  10,   715,  586,  561,  917,
    1020, 800, 640,  104, 864,  185,  566,  492,  709,  1009, 498,  859,  945,
    710,  433, 819,  411, 418,  649,  876,  733,  286,  326,  599,  986,  465,
    929,  272, 916,  935, 1,    87,   650,  609,  344,  598,  951,  221,  242,
    352,  635, 680,  464, 75,   256,  962,  336,  82,   383,  836,  993,  222,
    446,  110, 970,  591, 439,  677,  308,  186,  664,  188,  253,  770,  5,
    651,  467, 684,  139, 762,  315,  89,   507,  477,  406,  358,  753,  877,
    442,  32,  2,    997, 120,  946,  391,  220,  996,  125,  943,  749,  130,
    553,  385, 692,  814, 615,  396,  388,  610,  630,  957,  371,  741,  268,
    199,  740, 823,  588, 250,  269,  577,  254,  845,  825,  153,  62,   303,
    842,  453, 241,  114, 483,  868,  550,  952,  429,  434,  529,  503,  333,
    616,  913, 23,   872, 679,  497,  9,    841,  772,  150,  776,  52,   947,
    805,  613, 620,  343, 895,  812,  782,  138,  281,  778,  829,  289,  820,
    106,  400, 484,  402, 915,  720,  122,  724,  783,  436,  499,  605,  627,
    191,  607, 536,  91,  461,  108,  976,  851,  46,   676,  765,  109,  96,
    437,  323, 261,  330, 273,  311,  271,  972,  719,  306,  889,  707,  384,
    764,  979, 572,  475, 231,  519,  682,  832,  448,  356,  966,  1010, 404,
    757,  209, 548,  617, 228,  482,  156,  596,  1014, 405,  187,  860,  420,
    655,  276, 797,  243, 1003, 229,  950,  869,  163,  321,  848,  395,  302,
    803,  711, 515,  376, 886,  278,  128,  870,  1015, 989,  636,  1023, 573,
    704,  984, 601,  932, 18,   386,  926,  632,  647,  579,  365,  669,  910,
    768,  809, 526,  769, 66,   432,  213,  293,  48,   839,  217,  224,  813,
    899,  328, 177,  654, 401,  544,  154,  118,  736,  766,  495,  936,  767,
    523,  569, 458,  460, 685,  107,  718,  631,  844,  248,  933,  60,   227,
    374,  246, 247,  331, 894,  183,  279,  338,  387,  633,  565,  403,  744,
    849,  41,  942,  517, 389,  518,  133,  622,  35,   779,  362,  726,  1021,
    189,  787, 71,   539, 262,  423,  346,  856,  212,  748,  64,   930,  667,
    881,  781, 603,  817, 410,  378,  170,  225,  558,  29,   906,  174,  939,
    21,   292, 304,  663, 240,  793,  567,  456,  255,  811,  954,  735,  867,
    428,  991, 152,  528, 70,   263,  392,  697,  671,  155,  49,   301,  792,
    525,  959, 1001, 90,  924,  896,  826,  452,  968,  11,   542,  53,   327,
    777,  294, 94,   589, 547,  584,  416,  351,  713,  478,  55,   451,  36,
    708,  501, 132,  863, 54,   19,   142,  13,   934,  134,  30,   466,  716,
    295,  92,  447,  102, 181,  520,  644,  481,  470,  540,  583,  552,  786,
    690,  487, 394,  983, 259,  510,  50,   568,  533,  759,  992,  283,  39,
    360,  919, 167,  852, 42,   629,  1016, 454,  441,  1011, 0,    77,   197,
    234,  127, 159,  12,  898,  348,  265,  626,  739,  985};

using gc_policy = immer::memory_policy<immer::heap_policy<immer::gc_heap>,
                                       immer::no_refcount_policy,
                                       immer::default_lock_policy,
                                       immer::gc_transience_policy,
                                       false>;

using immvec = immer::flex_vector_transient<unsigned, gc_policy>;

void erase(immvec& v, unsigned idx)
{
    auto v2(v);
    v.take(idx);
    v2.drop(idx + 1);
    v.append(v2);
}

int main(int argc, char** argv)
{
    immvec vector;
    for (auto i : init)
        vector.push_back(i);

    erase(vector, 470);
    vector.push_back(224);
    erase(vector, 958);
}
