#include "build/temp/_test_Exception.c"
#include "CException.h"
#include "Exception.h"
#include "unity.h"










void setUp(void){}

void tearDown(void){}

void test_Exception_NeedToImplement(void){}





char *names[] = {"Ali", "David", "Ah Beng", "Sally"};



char *companies[] = {"Intel", "NXP", "Micron", "Nestle"};

char *namesInIntel[] = {"Sim", "Sum", "Som", "Sam"};

char *namesInNXP[] = {"Holly", "Molly", "Wolly", "Dolly"};

char *namesInMicron[] = {"Nick", "Nici", "Nico", "Nica"};

char *namesInNestle[] = {"Rom", "Rick", "Ram"};



char *getNameInTable(int index, char *names[], int maxSize)

{

  if(index >= maxSize || index < 0)

  {

    Throw(5);

  }

  return names[index];

}



char *getNameInCompany(int companyIdx, int nameIdx)

{

  char *name;

  switch(companyIdx)

  {

    case 0:

      name = getNameInTable(nameIdx, namesInIntel, 4);

      break;

    case 1:

      name = getNameInTable(nameIdx, namesInNXP, 4);

      break;

    case 2:

      name = getNameInTable(nameIdx, namesInMicron, 4);

      break;

    case 3:

      name = getNameInTable(nameIdx, namesInNestle, 3);

      break;

    default:

       name = 

             ((void *)0)

                 ;



  }

  return name;

}



char *getName(int index)

{

  if(index >= 4 || index < 0)

    Throw(3);

  return names[index];

}



void test_getName_given_1_expect_David(void)

{

  unsigned int e;

  char *name;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

  name = getName(4);

  printf("Name is %s \n", name);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    printf("Error code: %d\n", e);

  }

}



void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void)

{

  unsigned int e;

  char *name;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

  name = getName(-1);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    printf("ERR OUT OF BOUND\n");

    printf("Error code: %d\n", e);

  }

}



void test_getName_given_company1_people2_expect_wolly(void)

{

  unsigned int e;

  char *name;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

  name = getNameInCompany(1,2);

  UnityAssertEqualString((const char*)(("Wolly")), (const char*)((name)), (

 ((void *)0)

 ), (UNITY_UINT)(99));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityFail( (("Expect no exception throw but fai;")), (UNITY_UINT)(103));

  }

}
