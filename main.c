#include <stdio.h>
#include <stdint.h>

#define ls (5*(5*5+1)/2)

int main()
{
	int8_t m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25;
	uint32_t used=(uint32_t)0;
	uint32_t used1, used2, used3, used4, used5, used6, used7, used8, used9, used10, used11, used12, used13, used14, used15, used16, used17, used18, used19, used20, used21, used22, used23, used24, used25;
	long long int count=0;

	printf("line sum: %d\n", ls);

#define mfor(en) \
	for(m##en=1, used##en=used; m##en<=25; m##en++, used=used##en)

#define douse(en) \
	if(used&((uint32_t)1<<m##en)){ \
		continue; \
	}else{ \
		used|=(uint32_t)1<<m##en; \
	}

#define unuse(m) used&=~((uint32_t)1<<m)

#define tcont(c) \
	if(c){ \
		continue; \
	}

	/* left-top to right-below */
mfor(1){
		douse(1);
		mfor(7){
			douse(7);
			mfor(13){
				douse(13);
				tcont(m1+m7+m13<ls-25-24);
				mfor(19){
					douse(19);
					tcont(m1+m7+m13+m19<ls-25);
					m25=ls-(m19+m13+m7+m1);
					tcont(m25<=0);
					tcont(!(m1<m25));
					douse(25);
					/* Now the square is like:
					   o    
					    o   
					     o  
					      o 
					       -
					*/

					/* right-top to left-below */
					mfor(5){
						tcont(!(m1<m5));
						douse(5);
						mfor(9){
							douse(9);
							tcont(m5+m9+m13<ls-25-24);
							mfor(17){
								douse(17);
								tcont(m5+m9+m13+m17<ls-25);
								m21=ls-(m5+m9+m13+m17);
								tcont(m21<=0);
								tcont(!(m5<m21));
								douse(21);
								/* Now the square is like:
									o   o
									 o o 
									  o  
									 o o 
									-   -
								*/

								/* the first horizontal line from the top */
								mfor(2){
									douse(2);
									tcont(m1+m2+m5<ls-25-24);
									tcont(m2+m7+m17<ls-25-24);
									mfor(3){
										douse(3);
										tcont(m1+m2+m5+m3<ls-25);
										m4=ls-(m1+m2+m5+m3);
										tcont(m4<=0);
										douse(4);
										tcont(m4+m9+m19<ls-25-24);
										/* Now the square is like:
											ooo-o
											 o o 
											  o  
											 o o 
											-   -
										*/
	
										/* the second horizontal line from the top */
										mfor(6){
											douse(6);
											tcont(m6+m7+m9<ls-25-24);
											tcont(m1+m6+m21<ls-25-24);
											mfor(8){
												douse(8);
												tcont(m6+m7+m9+m8<ls-25);
												tcont(m3+m8+m13<ls-25-24);
												m10=ls-(m6+m7+m9+m8);
												tcont(m10<=0);
												douse(10);
												tcont(m5+m10+m25<ls-25-24);
												/* Now the square is like:
													ooo-o
													oooo-
													  o  
													 o o 
													-   -
												*/
	
												/* the fifth horizontal line from the top */
												mfor(22){
													douse(22);
													tcont(m21+m22+m25<ls-25-24);
													m12=ls-(m2+m7+m17+m22);
													tcont(m12<=0);
													douse(12);
													mfor(23){
														douse(23);
														tcont(m3+m8+m13+m23<ls-25);
														tcont(m21+m22+m25+m23<ls-25);
														m18=ls-(m3+m8+m13+m23);
														tcont(m18<=0);
														douse(18);
														tcont(m17+m18+m19<ls-25-24);
														m24=ls-(m21+m22+m25+m23);
														tcont(m24<=0);
														douse(24);
														tcont(m4+m9+m19+m24<ls-25);
														m14=ls-(m4+m9+m19+m24);
														tcont(m14<=0);
														douse(14);
														tcont(m12+m13+m14<ls-25-24);
														/* Now the square is like:
															ooo-o
															oooo-
															 -o- 
															 o-o 
															-oo--
														*/
	
														/* fill m11 manually and others automatically */
														mfor(11){
															douse(11);
															tcont(m11+m12+m13+m14<ls-25);
															tcont(m1+m6+m11+m21<ls-25);
															m15=ls-(m11+m12+m13+m14);
															tcont(m15<=0);
															douse(15);
															tcont(m5+m10+m15+m25<ls-25);
															m16=ls-(m1+m6+m11+m21);
															tcont(m16<=0);
															douse(16);
															tcont(m16+m17+m18+m19<ls-25);
															tcont((m5+m10+m15+m25)!=(m16+m17+m18+m19));
															m20=ls-(m16+m17+m18+m19);
															tcont(m20<=0);
															douse(20);

															count++;

#if 1
#elif 0
															printf("%2d %2d %2d %2d %2d\n", m1, m2, m3, m4, m5);
															printf("%2d %2d %2d %2d %2d\n", m6, m7, m8, m9, m10);
															printf("%2d %2d %2d %2d %2d\n", m11, m12, m13, m14, m15);
															printf("%2d %2d %2d %2d %2d\n", m16, m17, m18, m19, m20);
															printf("%2d %2d %2d %2d %2d\n", m21, m22, m23, m24, m25);
															puts("---------------");
#elif 0
															printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25);
#endif
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("last count: %lld\n", count);
	return 0;
}

/* vim: tabstop=2 ai nohlsearch */
