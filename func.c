	#include "func.h"
	#include  "stdbool.h"
	#include "arm_math.h"
	
	long yuvarla(float32_t x) 
{
     if (x >= 0)
      return (long) (x+0.5);
			else
      return (long) (x-0.5);
   }

	 	float32_t calculateSD_with_array(float32_t *data) //dizinin standart sapmasini hesaplar 
{
    float32_t sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i=0; i<1000; ++i)
    {
        sum += data[i];
    }

    mean = sum/1000;

    for(i=0; i<1000; ++i)
        standardDeviation += pow( (data[i] - mean), 2);

		standardDeviation=sqrt(standardDeviation/1000) ;
		
		
    return standardDeviation;
}

 	float32_t calculateSD(float32_t data[]) //dizinin standart sapmasini hesaplar 
{
    float32_t sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i=0; i<1000; ++i)
    {
        sum += data[i];
    }

    mean = sum/1000;

    for(i=0; i<1000; ++i)
        standardDeviation += pow( (data[i] - mean), 2);

		
		
		standardDeviation=sqrt(standardDeviation/999) ;
		
		
    return standardDeviation;
}


 	float32_t calculateMAV(float32_t data[],uint16_t n) //dizinin MEAN ABSOLUTE VALUE 
{
	
	
	//fILTRELEME KULLNIYORSAN ABS ALMAN GEREKECEK.
    float32_t sum = 0.0, mean, MAV = 0.0 ,temp=0.0;

    int i;

    for(i=0; i<n; ++i)
    {
        sum += data[i];
    }

    mean = sum/n;
		MAV=mean;

		
		
    return MAV;
}




	float32_t calculateA_with_Array(float32_t* data, uint16_t n)   //dizninn ortalamasini hesaplar
{
	
	
	
    float32_t sum = 0.0, mean=0;

    int i;

    for(i=0; i<n; i++)
    {
        sum += data[i];
    }

    mean = sum/n;

   return mean;
}






	 	float32_t calculateA(float32_t data[], uint16_t n)   //dizninn ortalamasini hesaplar
{
    float32_t sum = 0.0, mean=0;

    int i;

    for(i=0; i<n; i++)
    {
        sum += data[i];
    }

    mean = sum/n;

   return mean;
}






 uint8_t enkucuk_array(float32_t sayi[] ,uint8_t n)
	 {
	
		  float32_t kucuk =sayi[0];
		 uint8_t index =0;
		 
		  for(int i=0; i<n; i++)
        {              
			    	if( sayi[i]< kucuk)
						{ kucuk=sayi[i];
							index=i;
						}
       }
				
			 return index;
		 
 }
	 




 uint8_t enkucuk(float32_t sayi_0 ,float32_t sayi_1 ,float32_t sayi_2 )//3sayidan en kucugu bulur
	 {
		  if(sayi_0<sayi_1 && sayi_0<sayi_2)
		 return  0;  // sayi_0 ;
	 
	 	 if(sayi_1<sayi_2 && sayi_1<sayi_0)
	 return 1; // sayi_1;
		 
		 else 
		return	2;  //sayi_2;
	 }
	 
	 

int16_t  rolled_abs(float32_t deger)
{
		int16_t	deger_rolled=	yuvarla(deger);			
		
			
		if(deger_rolled<0) 
	 	{
			deger_rolled=deger_rolled*-1;
		}
		
		
		
	  return deger_rolled;
	
}

float32_t is_closest(  float32_t sw , float32_t sw1, float32_t sw2) {   //en yakin degisken hangisi onu bulur
	float32_t t=0;
	float32_t t1=0;
	float32_t t2=0;
	
	
	
t=	rolled_abs(sw-sw1);
		
t1=	rolled_abs(sw-sw2);

	
return	enkucuk(t1+t2,t1,t2);
}



/*****************************************************************/
	 int64_t  min = 100000;
   int64_t max = -100000;
	int64_t  counter=0;
  float32_t  buffer[1000];
void MinMax(float Values, int Window)
{

    
  int64_t  bufferSize = Window;
  //float32_t  buffer[counter];
   buffer[counter]	= Values;
    
    for (unsigned int i = 0; i < bufferSize; ++i)
    {
        if (buffer[i] < min)
        {
            min = buffer[i];
        }
        else if (buffer[i] > max)
        {
            max = buffer[i];
        }
    }
    
    ++counter;
    counter = counter % bufferSize;
}


//void MinMax::setValues (float Values, int Window)
//{
//    min = 100000;
//    max = -100000;
//    
//    bufferSize = Window;
//    buffer[counter] = Values;
//    
//    for (unsigned int i = 0; i < bufferSize; ++i)
//    {
//        if (buffer[i] < min)
//        {
//            min = buffer[i];
//        }
//        else if (buffer[i] > max)
//        {
//            max = buffer[i];
//        }
//    }
//    
//    ++counter;
//    counter = counter % bufferSize;
//}


//void MovingAverage::setValue (float Value, int NSamplesAvg)
//{
//    nSamplesAvgF = NSamplesAvg;
//    inputF[pointerF] = Value;
//    
//    for (int i = 0; i < nSamplesAvgF; ++i)
//    {
//        sumF = sumF + inputF[i];
//    }
//    
//    mavgF = sumF / nSamplesAvgF;
//    
//    sumF = 0;
//    ++pointerF;
//    pointerF = pointerF % nSamplesAvgF;
//}

//void MovingAverage::setValue (int Value, int NSamplesAvg)
//{
//    nSamplesAvgI = NSamplesAvg;
//    inputI[pointerI] = Value;
//    
//    for (int i = 0; i < nSamplesAvgI; ++i)
//    {
//        sumI = sumI + inputI[i];
//    }
//    
//    mavgI = sumI / nSamplesAvgI;
//    
//    sumI = 0;
//    ++pointerI;
//    pointerI = pointerI % nSamplesAvgI;
//    
//}


//void SecondOrderDifference::setValue (float Value)
//{
//    input = Value;
//    sod = (input - (2 * previousInputs[0]) + previousInputs[1]) * scaleFactor;
//    
//    previousInputs[inputPointer] = input;
//    ++inputPointer;
//    inputPointer = inputPointer % 2;
//}



//void ZeroCrossing::setValue (float Value, int BufferSize)
//{
//    bufferSizeF = BufferSize;
//    bufferF[counterF] = Value;
//    zeroCrossingRateF = 0;
//    
//    for (unsigned int i = 0; i < bufferSizeF; ++i)
//    {
//        if (bufferF[i] > 0 && bufferF[(i + 1) % bufferSizeF] < 0)
//        {
//            ++zeroCrossingRateF;
//        }
//        else if (bufferF[i] < 0 && bufferF[(i + 1) % bufferSizeF] > 0)
//        {
//            ++zeroCrossingRateF;
//        }
//        else continue;
//    }
//    
//    ++counterF;
//    counterF = counterF % bufferSizeF;
//}

//void ZeroCrossing::setValue (int Value, int BufferSize)
//{
//    bufferSizeI = BufferSize;
//    bufferI[counterI] = Value;
//    zeroCrossingRateI = 0;
//    
//    for (unsigned int i = 0; i < bufferSizeI; ++i)
//    {
//        if (bufferI[i] > 0 && bufferI[(i + 1) % bufferSizeI] < 0)
//        {
//            ++zeroCrossingRateI;
//        }
//        else if (bufferI[i] < 0 && bufferI[(i + 1) % bufferSizeI] > 0)
//        {
//            ++zeroCrossingRateI;
//        }
//        else continue;
//    }
//    
//    ++counterI;
//    counterI = counterI % bufferSizeI;
//}


/***************************************************************************/	
	
	
	
