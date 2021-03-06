#include "../../citron.h"
#include <stdio.h>
#include <math.h>

// ctr_object* ctr_ctype_uintt_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uinttarr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uint16_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uint16arr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uint32_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uint32arr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uint64_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_uint64arr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_intt_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_inttarr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_int16_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_int16arr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_int32_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_int32arr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_int64_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_int64arr_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_char_create(ctr_object* myself, ctr_argument* argumentList);
// ctr_object* ctr_ctype_chararr_create(ctr_object* myself, ctr_argument* argumentList);

#define CTR_GET_POINTER(thing, ptrname, type) type* ptrname = (type*)ctr_ctype_pointer_get(thing)
#define CTR_CONVERT_PTR_TO_CTR_NUMBER(ptr)  ctr_ctype_resource2number((void*) ptr)
#define CTR_DEF_FUNC_GET_PTR(type) ctr_object* ctr_ctypes_ptr_get_##type (ctr_object* myself, ctr_argument* argumentList) {\
  CTR_GET_POINTER(myself, ptr, type);\
  return ctr_build_number_from_float((float)(*ptr));\
}
#define CTR_DEF_FUNC_SET_PTR_NUMBER(type) ctr_object* ctr_ctypes_ptr_set_##type (ctr_object* myself, ctr_argument* argumentList) {\
  CTR_GET_POINTER(myself, ptr, type);\
  type value = argumentList->object->value.nvalue;\
  *ptr = (type)value;\
  return myself;\
}

ctr_object* ctr_ctype_char_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_chararr_create(ctr_object* myself, ctr_argument* argumentList);
intptr_t ctr_ctype_convert_to_ptr(void* resource);
ctr_object* ctr_ctype_create_shared_type();
ctr_object* ctr_ctype_int_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_int16_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_int16arr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_int32_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_int32arr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_int64_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_int64arr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_intarr_create(ctr_object* myself, ctr_argument* argumentList);
intptr_t ctr_ctype_pointer_get(ctr_object* from);
ctr_object* ctr_ctype_ptr2number(intptr_t ptr);
ctr_object* ctr_ctype_resource2number(void* resource);
void ctr_ctype_set_array_type_size(ctr_object* myself, char* basetype, int size);
ctr_object* ctr_ctype_tostring(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uint16_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uint16arr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uint32_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uint32arr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uint64_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uint64arr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uintt_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctype_uinttarr_create(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctypes_array_access(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctypes_build_char(const char value);
ctr_object* ctr_ctypes_build_int16(const int16_t value);
ctr_object* ctr_ctypes_build_int32(const int32_t value);
ctr_object* ctr_ctypes_build_int64(const int64_t value);
ctr_object* ctr_ctypes_build_int(const int value);
ctr_object* ctr_ctypes_build_uint16(const uint16_t value);
ctr_object* ctr_ctypes_build_uint32(const uint32_t value);
ctr_object* ctr_ctypes_build_uint64(const uint64_t value);
ctr_object* ctr_ctypes_build_uint(const uint8_t value);
//V
ctr_object* ctr_ctypes_build_charptr(const char* value);
ctr_object* ctr_ctypes_build_int16ptr(const int16_t* value);
ctr_object* ctr_ctypes_build_int32ptr(const int32_t* value);
ctr_object* ctr_ctypes_build_int64ptr(const int64_t* value);
ctr_object* ctr_ctypes_build_intptr(const int* value);
ctr_object* ctr_ctypes_build_uint16ptr(const uint16_t* value);
ctr_object* ctr_ctypes_build_uint32ptr(const uint32_t* value);
ctr_object* ctr_ctypes_build_uint64ptr(const uint64_t* value);
ctr_object* ctr_ctypes_build_uintptr(const uint8_t* value);
//^
ctr_object* ctr_ctypes_populate_from_string(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctypes_populate_string(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctypes_set_char(ctr_object* myself, ctr_argument* argumentList);
ctr_object* ctr_ctypes_to_char(ctr_object* myself, ctr_argument* argumentList);

int ctr_ctype_getarraysize(ctr_object* carray) {
  return ctr_internal_object_find_property(carray, ctr_build_string_from_cstring("carrsize"), CTR_CATEGORY_PRIVATE_PROPERTY)->value.nvalue;
}

ctr_object* ctr_ctype_tostring(ctr_object* myself, ctr_argument* argumentList) {
  return ctr_build_string_from_cstring("[C-Type]");
}

ctr_object* ctr_ctypes_populate_from_string(ctr_object* myself, ctr_argument* argumentList) {
  CTR_GET_POINTER(myself, mybuf, char);
  ctr_object* strobj = ctr_internal_cast2string(argumentList->object);
  int size = ctr_ctype_getarraysize(myself);
  if(size < strobj->value.svalue->vlen) {
    CtrStdFlow = ctr_build_string_from_cstring("Cannot overfill ctype array.");
    return myself;
  }
  strncpy(mybuf, strobj->value.svalue->value, fmin(strobj->value.svalue->vlen, size));
  return myself;
}

ctr_object* ctr_ctypes_populate_string(ctr_object* myself, ctr_argument* argumentList) {
  CTR_GET_POINTER(myself, mybuf, char);
  return ctr_build_string(mybuf, ctr_ctype_getarraysize(myself));
}

ctr_object* ctr_ctypes_set_char(ctr_object* myself, ctr_argument* argumentList) {
  CTR_GET_POINTER(myself, mybuf, char);
  ctr_object* strobj = ctr_internal_cast2string(argumentList->object);
  if(strobj->value.svalue->vlen == 0) {
    *mybuf = '\0';
    return myself;
  }
  char value = strobj->value.svalue->value[0];
  *mybuf = value;
  return myself;
}
ctr_object* ctr_ctypes_to_char(ctr_object* myself, ctr_argument* argumentList) {
  CTR_GET_POINTER(myself, mybuf, char);
  return ctr_build_string(mybuf, 1);
}
/*
 * Woof, Woof
 */
ctr_object* ctr_ctypes_array_access(ctr_object* myself, ctr_argument* argumentList) {
  CTR_GET_POINTER(myself, mybuf, void);
  ctr_object* strname = ctr_internal_object_find_property(myself, ctr_build_string_from_cstring("carrtype"), CTR_CATEGORY_PRIVATE_PROPERTY);
  int index = ctr_internal_cast2number(argumentList->object)->value.nvalue;
  if(index < 0 || strname == NULL) {
    CtrStdFlow = ctr_build_string_from_cstring("This Derp'd");
    return CtrStdNil;
  }
  char* type = ctr_internal_cast2string(strname)->value.svalue->value;
  int size = ctr_ctype_getarraysize(myself);
  if (strncmp(type, "uint64", 6) == 0) {
    uint64_t* buf = (uint64_t*)mybuf;
    int size = sizeof(buf)/sizeof(uint64_t);
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_uint64(*(buf+index));
  }
  else if (strncmp(type, "uint32", 6) == 0) {
    uint32_t* buf = (uint32_t*)mybuf;
    int size = sizeof(buf)/sizeof(uint32_t);
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_uint32(*(buf+index));
  }
  else if (strncmp(type, "uint16", 6) == 0) {
    uint16_t* buf = (uint16_t*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_uint16(*(buf+index));
  }
  else if (strncmp(type, "uint",   4) == 0) {
    uint8_t* buf = (uint8_t*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_uint(*(buf+index));
  }
  else if (strncmp(type, "int64",  5) == 0) {
    int64_t* buf = (int64_t*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_int64(*(buf+index));
  }
  else if (strncmp(type, "int32",  5) == 0) {
    int32_t* buf = (int32_t*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_int32(*(buf+index));
  }
  else if (strncmp(type, "int16",  5) == 0) {
    int16_t* buf = (int16_t*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_int16(*(buf+index));
  }
  else if (strncmp(type, "int",    3) == 0) {
    int* buf = (int*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_int(*(buf+index));
  }
  else if (strncmp(type, "char",   4) == 0) {
    char* buf = (char*)mybuf;
    if (index >= size) {CtrStdFlow = ctr_build_string_from_cstring("Index out of bounds."); return CtrStdFlow;}
    return ctr_ctypes_build_char(*(buf+index));
  }
  else {
    CtrStdFlow = ctr_build_string_from_cstring("Unknown ctype");
    return CtrStdNil;
  }
}

ctr_object* ctr_ctype_create_shared_type() {
  ctr_object* ptr = ctr_internal_create_object(CTR_OBJECT_TYPE_OTOBJECT);
  ptr->info.sticky = 1; //Pointer types MUST persist
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("toString"), &ctr_ctype_tostring);
  return ptr;
}

intptr_t ctr_ctype_pointer_get(ctr_object* from) {
  return (intptr_t)ctr_internal_object_find_property(from, ctr_build_string_from_cstring("ptr"), CTR_CATEGORY_PRIVATE_PROPERTY);
}
intptr_t ctr_ctype_convert_to_ptr(void* resource) {
  return (intptr_t)resource;
}
ctr_object* ctr_ctype_ptr2number(intptr_t ptr) {
  return ctr_build_number_from_float(ptr);
}
ctr_object* ctr_ctype_resource2number(void* resource) {
  return ctr_ctype_ptr2number(ctr_ctype_convert_to_ptr(resource));
}

void ctr_ctype_set_array_type_size(ctr_object* myself, char* basetype, int size) {
  ctr_internal_object_set_property(myself, ctr_build_string_from_cstring("carrtype"), ctr_build_string_from_cstring(basetype), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_internal_object_set_property(myself, ctr_build_string_from_cstring("carrsize"), ctr_build_number_from_float(size), CTR_CATEGORY_PRIVATE_PROPERTY);
}


// CTR_DEF_FUNC_GET_PTR(char);
// CTR_DEF_FUNC_GET_PTR(int);
// CTR_DEF_FUNC_GET_PTR(int16_t);
// CTR_DEF_FUNC_GET_PTR(int32_t);
// CTR_DEF_FUNC_GET_PTR(int64_t);
// CTR_DEF_FUNC_GET_PTR(uint8_t);
// CTR_DEF_FUNC_GET_PTR(uint16_t);
// CTR_DEF_FUNC_GET_PTR(uint32_t);
// CTR_DEF_FUNC_GET_PTR(uint64_t);
//
// ctr_object* ctr_ctypes_ptr_set_char (ctr_object* myself, ctr_argument* argumentList) {
//   CTR_GET_POINTER(myself, ptr, char);
//   char value = *(ctr_internal_cast2string(argumentList->object)->value.svalue->value);
//   *ptr = value;
//   return myself;
// }
//
// CTR_DEF_FUNC_SET_PTR_NUMBER(int);
// CTR_DEF_FUNC_SET_PTR_NUMBER(int16_t);
// CTR_DEF_FUNC_SET_PTR_NUMBER(int32_t);
// CTR_DEF_FUNC_SET_PTR_NUMBER(int64_t);
// CTR_DEF_FUNC_SET_PTR_NUMBER(uint8_t);
// CTR_DEF_FUNC_SET_PTR_NUMBER(uint16_t);
// CTR_DEF_FUNC_SET_PTR_NUMBER(uint32_t);
// CTR_DEF_FUNC_SET_PTR_NUMBER(uint64_t);
// FROM POINTER

// ctr_object* ctr_ctypes_build_charptr(const char* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("char:"), &ctr_ctypes_ptr_set_char);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("char"),  &ctr_ctypes_ptr_get_char);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_int16ptr(const int16_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int:"), &ctr_ctypes_ptr_set_int16_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int"),  &ctr_ctypes_ptr_get_int16_t);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_int32ptr(const int32_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int:"), &ctr_ctypes_ptr_set_int32_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int"),  &ctr_ctypes_ptr_get_int32_t);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_int64ptr(const int64_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int:"), &ctr_ctypes_ptr_set_int64_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int"),  &ctr_ctypes_ptr_get_int64_t);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_intptr(const int* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int:"), &ctr_ctypes_ptr_set_int);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("int"),  &ctr_ctypes_ptr_get_int);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_uint16ptr(const uint16_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint:"), &ctr_ctypes_ptr_set_uint16_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint"),  &ctr_ctypes_ptr_get_uint16_t);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_uint32ptr(const uint32_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint:"), &ctr_ctypes_ptr_set_uint32_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint"),  &ctr_ctypes_ptr_get_uint32_t);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_uint64ptr(const uint64_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint:"), &ctr_ctypes_ptr_set_uint64_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint"),  &ctr_ctypes_ptr_get_uint64_t);
//   return ptr;
// }
// ctr_object* ctr_ctypes_build_uintptr(const uint8_t* value) {
//   ctr_object* ptr = ctr_ctype_create_shared_type();
//   ptr->link = CtrStdNumber;
//   ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(value), CTR_CATEGORY_PRIVATE_PROPERTY);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint:"), &ctr_ctypes_ptr_set_uint8_t);
//   ctr_internal_create_func (ptr, ctr_build_string_from_cstring("uint"),  &ctr_ctypes_ptr_get_uint8_t);
//   return ptr;
// }

// NEW VALUES

ctr_object* ctr_ctype_uintt_create(ctr_object* myself, ctr_argument* argumentList) {
    ctr_object* ptr = ctr_ctype_create_shared_type();
    ptr->link = myself;
    uint8_t* p = ctr_heap_allocate_tracked(sizeof(unsigned int));
    *p = 0;
    ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
    return ptr;
}
ctr_object* ctr_ctype_uinttarr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  uint8_t* p = ctr_heap_allocate_tracked(sizeof(unsigned int)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "uint", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_uint16_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  uint16_t* p = ctr_heap_allocate_tracked(sizeof(uint16_t));
  *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_uint16arr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  uint16_t* p = ctr_heap_allocate_tracked(sizeof(uint16_t)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "uint16", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_uint32_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  uint32_t* p = ctr_heap_allocate_tracked(sizeof(uint32_t)); *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_uint32arr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  uint32_t* p = ctr_heap_allocate_tracked(sizeof(uint32_t)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "uint32", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_uint64_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  uint64_t* p = ctr_heap_allocate_tracked(sizeof(uint64_t)); *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_uint64arr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  uint64_t* p = ctr_heap_allocate_tracked(sizeof(uint64_t)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "uint64", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_int_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int* p = ctr_heap_allocate_tracked(sizeof(int)); *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_intarr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  int* p = ctr_heap_allocate_tracked(sizeof(int)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "int", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_int16_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int16_t* p = ctr_heap_allocate_tracked(sizeof(int16_t)); *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_int16arr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  int16_t* p = ctr_heap_allocate_tracked(sizeof(int16_t)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "int16", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_int32_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int32_t* p = ctr_heap_allocate_tracked(sizeof(int32_t)); *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_int32arr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  int32_t* p = ctr_heap_allocate_tracked(sizeof(int32_t)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "int32", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_int64_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int64_t* p = ctr_heap_allocate_tracked(sizeof(int64_t)); *p = 0;
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  return ptr;
}
ctr_object* ctr_ctype_int64arr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  int64_t* p = ctr_heap_allocate_tracked(sizeof(int64_t)*count);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "int64", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}
ctr_object* ctr_ctype_char_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  char* p = ctr_heap_allocate_tracked(sizeof(char)); *p = '\0';
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("char:"), &ctr_ctypes_set_char);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("char"), &ctr_ctypes_to_char);
  return ptr;
}

ctr_object* ctr_ctypes_build_uint64(const uint64_t value) {
  ctr_object* obj = ctr_ctype_uint64_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, uint64_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_uint32(const uint32_t value) {
  ctr_object* obj = ctr_ctype_uint32_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, uint32_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_uint16(const uint16_t value) {
  ctr_object* obj = ctr_ctype_uint16_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, uint16_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_uint  (const uint8_t value) {
  ctr_object* obj = ctr_ctype_uintt_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, uint8_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_int64 (const int64_t value) {
  ctr_object* obj = ctr_ctype_int64_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, int64_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_int32 (const int32_t value) {
  ctr_object* obj = ctr_ctype_int32_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, int32_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_int16 (const int16_t value) {
  ctr_object* obj = ctr_ctype_int16_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, int16_t);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_int   (const int value) {
  ctr_object* obj = ctr_ctype_int_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, int);
  *ptr = value;
  return obj;
}
ctr_object* ctr_ctypes_build_char  (const char value) {
  ctr_object* obj = ctr_ctype_char_create(CtrStdObject, NULL);
  CTR_GET_POINTER(obj, ptr, char);
  *ptr = value;
  return obj;
}

ctr_object* ctr_ctype_chararr_create(ctr_object* myself, ctr_argument* argumentList) {
  ctr_object* ptr = ctr_ctype_create_shared_type();
  ptr->link = myself;
  int count = ((int)(ctr_internal_cast2number(argumentList->object)->value.nvalue));
  char* p = ctr_heap_allocate_tracked(sizeof(char)*count);
  printf("%p\n", (void*)p);
  ctr_internal_object_set_property(ptr, ctr_build_string_from_cstring("ptr"), CTR_CONVERT_PTR_TO_CTR_NUMBER(p), CTR_CATEGORY_PRIVATE_PROPERTY);
  ctr_ctype_set_array_type_size(ptr, "char", count);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("fromString:"), &ctr_ctypes_populate_from_string);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("toCtrString"), &ctr_ctypes_populate_string);
  ctr_internal_create_func(ptr, ctr_build_string_from_cstring("at:"), &ctr_ctypes_array_access);
  return ptr;
}


void begin() {
  ctr_object* CTypes = ctr_internal_create_object(CTR_OBJECT_TYPE_OTOBJECT);
  CTypes->link = CtrStdObject;

  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int"),        &ctr_ctype_int_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int16"),      &ctr_ctype_int16_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int32"),      &ctr_ctype_int32_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int64"),      &ctr_ctype_int64_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint"),       &ctr_ctype_uintt_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint16"),     &ctr_ctype_uint16_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint32"),     &ctr_ctype_uint32_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint64"),     &ctr_ctype_uint64_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("char"),       &ctr_ctype_char_create);

  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("intarr:"),    &ctr_ctype_intarr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int16arr:"),  &ctr_ctype_int16arr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int32arr:"),  &ctr_ctype_int32arr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("int64arr:"),  &ctr_ctype_int64arr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uintarr:"),   &ctr_ctype_uinttarr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint16arr:"), &ctr_ctype_uint16arr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint32arr:"), &ctr_ctype_uint32arr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("uint64arr:"), &ctr_ctype_uint64arr_create);
  ctr_internal_create_func(CTypes, ctr_build_string_from_cstring("chararr:"),   &ctr_ctype_chararr_create);

  ctr_internal_object_add_property(CtrStdWorld, ctr_build_string_from_cstring("CTypes"), CTypes, 0);

}
