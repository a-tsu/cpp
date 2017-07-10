#include <string>  
  
std::string UrlEncode( const std::string & str )  
{
 std::string retStr;
 
 std::string::size_type length = str.size();   
 for ( std::string::size_type i = 0 ; i < length ; i++ )  
 {
  if (( '0' <= str[ i ] && str[ i ] <= '9' ) ||  
   ( 'a' <= str[ i ] && str[ i ] <= 'z' ) ||  
   ( 'A' <= str[ i ] && str[ i ] <= 'Z' ) ||  
   str[ i ] == '-'   || str[ i ] == '.'   ||  
   str[ i ] == '_'   || str[ i ] == '~' )  
  {  
   // 数字/アルファベット/[-][.][_][~]はそのまま  
   retStr += str[ i ];  
  }  
  else  
  {  
   retStr += '%';  
   char tmp[ 3 ];  
   snprintf( tmp, 3, "%X", static_cast< unsigned char >( str[ i ] ));  
   retStr += tmp;  
  }
 }

 return retStr;  
} 

int main() {
    printf("urlencoded: %s", UrlEncode("test123.!'()*-._~ $#%&").c_str());
}
