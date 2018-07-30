//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: HelloWorldData.h
//  Source: ../HelloWorldData.idl
//  Generated: Mon Jun  4 18:07:00 2018
//  OpenSplice 6.7.180404OSS
//  
//******************************************************************
#ifndef _HELLOWORLDDATA_H_
#define _HELLOWORLDDATA_H_
#ifndef OPENSPLICE_ISOCXX_PSM
#define OPENSPLICE_ISOCXX_PSM
#endif

#include "sacpp_mapping.h"
#include <dds/core/ddscore.hpp>


namespace HelloWorldData
{
   class Msg;

   class Msg OSPL_DDS_FINAL
   {
   public:
         Msg() {}
         explicit Msg(
                  DDS::Long userID,
                  const ::std::string& message)         :
                           userID_(userID),
                           message_(message) {}
#ifdef OSPL_DDS_CXX11
#  ifdef OSPL_CXX11_NO_FUNCTION_DEFAULTS
         Msg(const Msg& _other)
         :
                           userID_(_other.userID_),
                           message_(_other.message_)
         {}
         Msg(Msg&& _other)
         :
                           userID_(::std::move(_other.userID_)),
                           message_(::std::move(_other.message_))
         {}
         Msg& operator=(Msg&& _other)
         {
                  if (this != &_other)
                  {
                           userID_ = ::std::move(_other.userID_);
                           message_ = ::std::move(_other.message_);
                  }
                  return *this;
         }
         Msg& operator=(const Msg& _other)
         {
                  if (this != &_other)
                  {
                           userID_ = _other.userID_;
                           message_ = _other.message_;
                  }
                  return *this;
         }
#  else
         Msg(const Msg& _other) = default;
         Msg(Msg&& _other) = default;
         Msg& operator=(Msg&& _other) = default;
         Msg& operator=(const Msg& _other) = default;
#  endif
#endif
         DDS::Long userID() const { return this->userID_; }
         DDS::Long& userID() { return this->userID_; }
         void userID(DDS::Long _val_) { this->userID_ = _val_; }
         const ::std::string& message() const { return this->message_; }
         ::std::string& message() { return this->message_; }
         void message(const ::std::string& _val_) { this->message_ = _val_; }
#ifdef OSPL_DDS_CXX11
         void message(::std::string&& _val_) { this->message_ = _val_; }
#endif
         bool operator==(const Msg& _other) const
         {
                  return userID_ == _other.userID_ &&
                  message_ == _other.message_;
         }
         bool operator!=(const Msg& other) const
         {
                  return !(*this == other);
         }
         DDS::Long userID_;
         ::std::string message_;
   };

}




#endif