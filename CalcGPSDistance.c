#define pi 3.14159265359		
#include <Math.h>


float deg2rad(float deg){
	float rad = deg*(pi/180);
	return rad;
}

float CalcGPSDistance(float lat1, float lon1, float lat2, float lon2){
/*		int R = 6371; // Radius of the earth in km										
  // distance between latitudes and longitudes
		float  a ;
    float Lat = deg2rad(lat2 -                                        lat1);
    float Lon = deg2rad(lon2 - lon1);
  
		a = (sin( Lat / 2) * sin(Lat / 2)) + 
				(cos(deg2rad(lat1)) * cos(deg2rad(lat2)))*
				(sin(Lon/2) * sin(Lon/2)) ;						 
		return (2000 *R* atan2(sqrt(a), sqrt(1-a))); 
		//d = R * c; // Distance in km
		//return c;*/
	return(1000*( sqrt(71.5*71.5* ((lon2-lon1)*(lon2-lon1)) + 111.3*111.3*((lat1-lat2)*(lat1-lat2)))));
	
}
