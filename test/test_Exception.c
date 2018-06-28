#include "unity.h"
#include "Exception.h"
#include "CException.h"

#define ERR_OUT_OF_BOUND    3
#define ERR_UNKNOWN_COMPANY 4
#define ERR_UNKNOWN_PEOPLE  5

void setUp(void){}
void tearDown(void){}
void test_Exception_NeedToImplement(void){}

//name is array 3 of pointes to char
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
    Throw(ERR_UNKNOWN_PEOPLE);
  }
  return names[index];
}

char *getNameInCompany(int companyIdx, int nameIdx)
{
  char *name;
  switch(companyIdx)
  {
    case 0: //Intel
      name = getNameInTable(nameIdx, namesInIntel, 4);
      break;
    case 1://NXP
      name = getNameInTable(nameIdx, namesInNXP, 4);
      break;
    case 2://Micron
      name = getNameInTable(nameIdx, namesInMicron, 4);
      break;
    case 3://Nestle
      name = getNameInTable(nameIdx, namesInNestle, 3);
      break;
    default:
       name = NULL;
      //Throw(ERR_UNKNOWN_COMPANY);
  }
  return name;
}

char *getName(int index)
{
  if(index >= 4 || index < 0)
    Throw(ERR_OUT_OF_BOUND);
  return names[index];
}

void test_getName_given_1_expect_David(void)
{
  CEXCEPTION_T e;
  char *name;
  Try
  {
  name = getName(4);
  printf("Name is %s \n", name);
  }
  Catch(e)
  {
    printf("Error code: %d\n", e);
  }
}

void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void)
{
  CEXCEPTION_T e;
  char *name;
  Try
  {
  name = getName(-1);
  }
  Catch(e)
  {
    printf("ERR OUT OF BOUND\n");
    printf("Error code: %d\n", e);
  }
}

void test_getName_given_company1_people2_expect_wolly(void)
{
  CEXCEPTION_T e;
  char *name;
  Try
  {
  name = getNameInCompany(1,2);
  TEST_ASSERT_EQUAL_STRING("Wolly",name);
  }
  Catch(e)
  {
    TEST_FAIL_MESSAGE("Expect no exception throw but fai;");
  }
}
