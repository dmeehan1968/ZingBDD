//
//  Arguments.h
//  ZingBDD
//
//  Created by Dave Meehan on 05/02/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_Arguments_h
#define ZingBDD_Arguments_h

#include <iomanip>

namespace ZingBDD {

    template
    <
    size_t ArgCount,
    typename T1 = bool,
    typename T2 = bool,
    typename T3 = bool,
    typename T4 = bool,
    typename T5 = bool,
    typename T6 = bool
    >
    class Arguments {
        
    public:
        Arguments(const T1 &a1 = {}, const T2 &a2 = {}, const T3 &a3 = {},
                  const T4 &a4 = {}, const T5 &a5 = {}, const T6 &a6 = {})
        : _a1(a1), _a2(a2), _a3(a3), _a4(a4), _a5(a5), _a6(a6) {}
        
        bool operator == (const Arguments<ArgCount, T1, T2, T3, T4, T5, T6> &other) {
            
            return  _a1 == other._a1 &&
            _a2 == other._a2 &&
            _a3 == other._a3 &&
            _a4 == other._a4 &&
            _a5 == other._a5 &&
            _a6 == other._a6;
        }
        
        size_t argCount() const {
            return ArgCount;
        }
        
        void toString(std::ostream &stream) const {
            
            stream << "{ ";
            if (argCount() >= 1) { stream << pretty(_a1); }
            if (argCount() >= 2) { stream << ", " << pretty(_a2); }
            if (argCount() >= 3) { stream << ", " << pretty(_a3); }
            if (argCount() >= 4) { stream << ", " << pretty(_a4); }
            if (argCount() >= 5) { stream << ", " << pretty(_a5); }
            if (argCount() >= 6) { stream << ", " << pretty(_a6); }
            stream << " }";
            
        }
        
        /// Match non-integral types
        
        template
        <
        typename T
        >
        std::string pretty(const T &value) const {
            std::ostringstream os;
            
            os << "Object value @ " << &value;
            
            return os.str();
        }
        
        
        /// Match integral types
        
        template
        <
        typename T,
        typename X = typename std::enable_if<
        std::is_integral<std::decay<T>>::value
        >::type
        >
        std::string pretty(const T &value) const {
            std::ostringstream os;
            
            os << value;
            
            return os.str();
        }
        
        /// Match unsigned char
        
        std::string pretty(const unsigned char &value) const {
            
            std::ostringstream os;
            
            std::ios_base::fmtflags flags = os.flags();
            os.flags(std::ios::hex | std::ios::right);
            os  << "0x"
            << std::setw(2)
            << std::setfill('0')
            << (int)value;
            
            os.flags(flags);
            
            return os.str();
        }
        
        /// Match signed char
        
        std::string pretty(const char &value) const {
            return pretty((unsigned char) value);
        }
        
        /// Match bool
        
        std::string pretty(const bool &value) const {
            std::ostringstream os;
            os << std::boolalpha << (int)value << std::noboolalpha;
            return os.str();
        }
        
    private:
        
        T1 _a1;
        T2 _a2;
        T3 _a3;
        T4 _a4;
        T5 _a5;
        T6 _a6;
        
    };
    
    template
    <
    size_t ArgCount,
    typename T1 = bool,
    typename T2 = bool,
    typename T3 = bool,
    typename T4 = bool,
    typename T5 = bool,
    typename T6 = bool
    >
    std::ostream &operator<< (std::ostream &stream,
                              const Arguments<ArgCount, T1, T2, T3, T4, T5, T6> &args) {
        
        args.toString(stream);
        
        return stream;
    }

}

#endif
