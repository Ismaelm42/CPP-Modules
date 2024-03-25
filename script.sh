#!/bin/bash

i=1
while [ $i -le $# ]; do
    # Variables
    name=${!i}
    header_file="${name}.hpp"
    class_file="${name}.cpp"
    header=$(echo ${!i} | tr '[a-z]' '[A-Z]')
#header    
    cat <<EOF > "$header_file"
#ifndef ${header}_HPP
#define ${header}_HPP
#include <iostream>

class $name
{	
	public:
		$name();
		$name(const $name& rhs);
		$name& operator=(const $name& rhs);
		~$name();
};

#endif
EOF
#class
    cat <<EOF > "$class_file"
#include "${header_file}"

${name}::${name}()
{

}

${name}::${name}(const ${name}& rhs)
{

}

${name}& ${name}::operator=(const ${name}& rhs)
{

}

${name}::~${name}()
{

}
EOF
    ((i++))
	done
