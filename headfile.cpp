#include "stdafx.h"
#include "headfile.h"
#include <iostream>
#include <math.h>

using namespace std;


Line::Line(Point &p1, Point &p2) {
  m_p1.x = p1.x;
  m_p1.y = p1.y;
  m_p2.x = p2.x;
  m_p2.y = p2.y;
  A = 0;
  B = 0;
  C = 0;
}

Line::Line() {
  m_p1.x = 0;
  m_p1.y = 0;
  m_p2.x = 0;
  m_p2.y = 0;
  A = 0;
  B = 0;
  C = 0;

}

Line::Line(Point *f_p1, Point *f_p2){
  m_p1.x = f_p1->x;
  m_p1.y = f_p1->y;
  m_p2.x = f_p2->x;
  m_p2.y = f_p2->y;
  A = 0;
  B = 0;
  C = 0;


}

void Line::Draw(CPaintDC& dc) {
  dc.MoveTo(m_p1.x, m_p1.y);
  dc.LineTo(m_p2.x, m_p2.y);
}

int Line::getSign(Point &p) {
  int res = A * p.x + B * p.y + C;
  if (res == 0)
    return 0;
  if (res > 0)
    return 1;
  return -1;
}

int Line::checkCrossed(Line &f_l) {
  if (getSign(f_l.getP1()) * getSign(f_l.getP2()) < 0 && f_l.getSign(m_p1) * f_l.getSign(m_p2) < 0)
    return 1;
  return 0;
}

void Line::SetP(Point &p1, Point &p2) {
  m_p1 = p1;
  m_p2 = p2;

  A = p2.y - p1.y;
  B = p1.x - p2.x;
  C = p1.y * (p2.x - p1.x) - p1.x * (p2.y - p1.x);

}

double Line::LineLenght() {
  double dx = m_p1.x - m_p2.x;
  double dy = m_p1.y - m_p2.y;
  return sqrt((dx * dx) + (dy * dy));
}





Array :: Array(){
  p1.x = 0;
  p1.y = 0;
  p2.x = 0;
  p2.y = 0;
  abs = 0;

}

Array :: Array(Point &p1,Point &p2,float &abs){
	p1.x = p1.x;
    p1.y = p1.y;
	p2.x = p2.x;
    p2.y = p2.y;
    this->abs = abs;

}

Array :: Array(Point *f_p1,Point *f_p2, float *f_abs){
  p1.x = f_p1->x;
  p1.y = f_p1->y;
  p2.x = f_p2->x;
  p2.y = f_p2->y;
  this->abs = *f_abs;


}


Array & Array ::operator=(const Array &other)
	{
	  this->p1 = other.p1;
	  this->p2 = other.p2;
	  this->abs = other.abs;

	  return *this;
	
	}









void CorrectDraw(CPaintDC& dc,Point *fpp_pointCounter,int *size,int *lpi_TWO_pointCounter ){
	
	int li_i, li_j,lf_min_cosa_ind,q,lf_ax,lf_ay,lf_bx,lf_by,occupancy_meter_array_TWO=0;
	float lf_ab,lf_absa,lf_absb,lf_min_cosa,lf_cosa;
	Point *lpp_begin,*lpp_continue,*lpp_time,lp_tmp , la;
	

	
//find point for begin figure
	

	additional_function(lpi_TWO_pointCounter, size ,fpp_pointCounter);
	
		*(lpi_TWO_pointCounter+occupancy_meter_array_TWO)=0;
		occupancy_meter_array_TWO++;
		*(lpi_TWO_pointCounter+occupancy_meter_array_TWO)=1;
		occupancy_meter_array_TWO++;
	//	for (int z=0;z<2;z++)
	//	li_i=lpi_TWO_pointCounter[z];



	
	lf_min_cosa=1;

	lpp_continue = (fpp_pointCounter+1); 
	lpp_begin = fpp_pointCounter;
//ax=x1-x0
	lf_ax = lpp_continue->x - lpp_begin->x;
	lf_ay = lpp_continue->y - lpp_begin->y;

	lpp_time = (fpp_pointCounter); //x2
bool flag=false;
	for (li_i=0;li_i<*size;li_i++){
       // li_j=( li_i==0 ? 2:0);
		for (li_j=0;li_j<*size;li_j++,lpp_time++) {			  			
 			

			for(q=0;q<occupancy_meter_array_TWO;q++){
			if (li_j==lpi_TWO_pointCounter[q])
			flag=true;
			
			}
			if (flag){
			flag = false;
			continue;
			}
			
		//bx=x2-x1
				lf_bx = lpp_continue->x - lpp_time->x;
				lf_by = lpp_continue->y - lpp_time->y;

				lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
				lf_absb = sqrt(abs(lf_bx) * abs(lf_bx) + abs(lf_by) * abs(lf_by));

				lf_ab = lf_bx*lf_ax+lf_ay*lf_by;
				lf_cosa=lf_ab / (lf_absa*lf_absb);
				if (lf_min_cosa>lf_cosa){
					lf_min_cosa_ind=li_j;
					lf_min_cosa=lf_cosa;
				}

		}
	// обьекты класа создавать динамически


	
				
			*(lpi_TWO_pointCounter+occupancy_meter_array_TWO) = lf_min_cosa_ind;
			occupancy_meter_array_TWO++;


		lpp_begin=lpp_continue;
		lpp_continue=(fpp_pointCounter+lf_min_cosa_ind);

		lf_ax = lpp_continue->x - lpp_begin->x;
		lf_ay = lpp_continue->y - lpp_begin->y;
		lpp_time=fpp_pointCounter;

		lf_min_cosa_ind=0;
		lf_min_cosa=1;

	}
			*(lpi_TWO_pointCounter + occupancy_meter_array_TWO) = *lpi_TWO_pointCounter;

	  	for(li_i=0;li_i<*size;li_i++){
	 		Line L_l((fpp_pointCounter+*(lpi_TWO_pointCounter+li_i)),(fpp_pointCounter+*(lpi_TWO_pointCounter+li_i+1)));
			L_l.Draw(dc);
			li_j=*(lpi_TWO_pointCounter+li_i);
			if (li_i != *size)
			li_j=*(lpi_TWO_pointCounter+li_i+1);

		}


		
}



	/*создать объект класса лайн с точек П1 и П0
потом создать такойже обьект с точек П1 и точки под номером ж в масиве который мы передаем в функцию*/





void DrawFigure(CPaintDC& dc,Point *fpp_pointCounter,int *size,int *lpi_TWO_pointCounter){

       /* int li_i,li_j;
       	for(li_i=0;li_i<*size;li_i++){
	 		Line L_l((fpp_pointCounter+*(lpi_TWO_pointCounter+li_i)),(fpp_pointCounter+*(lpi_TWO_pointCounter+li_i+1)));
			L_l.Draw(dc);
			li_j=*(lpi_TWO_pointCounter+li_i);
			if (li_i != *size)
			li_j=*(lpi_TWO_pointCounter+li_i+1);

		}*/

	
}







void diagonally(CPaintDC& dc,HWND f_hWnd,int *lpi_TWO_pointCounter, int size,Point *pointCounter){
		int li_i,number_diagonals,li_bla=0,max_d_ind,li_j,lip_ax,lim_ax,lip_ay,lim_ay,lip_axx,lim_axx,lip_ayy,lim_ayy ;
		Point *lpp_begin,*lpp_continue,coord_circle_1,coord_circle_2,coord_circle_3,coord_circle_4,a;
		float lf_absa,lf_ax,lf_ay,max_d,min_d;
	number_diagonals=(size*(size-3))/2;
	


		CPen pen(PS_SOLID,1,RGB(200,5,0)); 
	
    Array *arr,as;
	arr= new Array [number_diagonals*5];
if(!arr)
return;

		lpp_begin=(pointCounter);
		lpp_continue=(pointCounter);




	for(li_i=0;li_i<size;li_i++,lpp_begin++){

		for (li_j=0;li_j<size;li_j++,lpp_continue++){

			

		
					lf_ax = lpp_continue->x - lpp_begin->x; 
					lf_ay = lpp_continue->y - lpp_begin->y;
					lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));

			arr[li_bla].p1 = *lpp_begin;
			
			arr[li_bla].p2 = *lpp_continue;
			
			arr[li_bla].abs = lf_absa;
			li_bla++;


		}
		lpp_continue=(pointCounter);
		
	}	



max_d=arr[0].abs;

 
for (li_i=0;li_i<li_bla-1;li_i++){
	if (max_d < (arr+li_i)->abs){
	max_d = arr[li_i].abs;
	max_d_ind = li_i;
 
	}
	lf_ax = (arr+li_i)->abs;
}
			
	as = arr[0];
	arr[0] = arr[max_d_ind];
	arr[max_d_ind] = arr[0];

	max_d=arr[1].abs;
	max_d_ind=1;

for (li_i=1;li_i<li_bla-1;li_i++){
	if (max_d < (arr+li_i)->abs && (arr)->abs != (arr+li_i)->abs){
	max_d = arr[li_i].abs;
	max_d_ind = li_i;
	}
	lf_ax = (arr+li_i)->abs;
}

    as = arr[1];
	arr[1] = arr[max_d_ind];
	arr[max_d_ind] = arr[1];

min_d=10000;

for (li_i=0;li_i<li_bla-1;li_i++){
	if (min_d > (arr+li_i)->abs && (arr+li_i)->abs != 0){
	min_d = (arr+li_i)->abs;
	
	}
	lf_ax = (arr+li_i)->abs;
}



a = arr[0].p1;
a = arr[0].p2;
a = arr[1].p1;
a = arr[1].p2;





if (size != 3){

		coord_circle_1 = arr[0].p1;

		coord_circle_2 = arr[0].p2;

	lim_ax = coord_circle_1.x - ((min_d/2)*sqrt(2));
	lim_ay = coord_circle_1.y - ((min_d/2)*sqrt(2));
	lip_ax = coord_circle_1.x + ((min_d/2)*sqrt(2));
	lip_ay = coord_circle_1.y + ((min_d/2)*sqrt(2));

	lim_axx = coord_circle_2.x - ((min_d/2)*sqrt(2));
	lim_ayy = coord_circle_2.y - ((min_d/2)*sqrt(2));
	lip_axx = coord_circle_2.x + ((min_d/2)*sqrt(2));
	lip_ayy = coord_circle_2.y + ((min_d/2)*sqrt(2));


///////////////////
	lf_ax = coord_circle_2.x - coord_circle_1.x;
	lf_ay = coord_circle_2.y - coord_circle_1.y;

	lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
///////////////////

	if (lf_absa<=min_d){
		
		dc.SelectObject(&pen);


		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);




		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);



	}

	else{
		dc.Arc( lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);
	}




		coord_circle_3 = arr[1].p1;
		coord_circle_4 = arr[1].p2;

	lim_ax = coord_circle_3.x - ((min_d/2)*sqrt(2));
	lim_ay = coord_circle_3.y - ((min_d/2)*sqrt(2));
	lip_ax = coord_circle_3.x + ((min_d/2)*sqrt(2));
	lip_ay = coord_circle_3.y + ((min_d/2)*sqrt(2));

	lim_axx = coord_circle_4.x - ((min_d/2)*sqrt(2));
	lim_ayy = coord_circle_4.y - ((min_d/2)*sqrt(2));
	lip_axx = coord_circle_4.x + ((min_d/2)*sqrt(2));
	lip_ayy = coord_circle_4.y + ((min_d/2)*sqrt(2));


///////////////////
	lf_ax = coord_circle_4.x - coord_circle_3.x;
	lf_ay = coord_circle_4.y - coord_circle_3.y;

	lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
//////////////////

	

	if (lf_absa<=min_d){
		dc.SelectObject(&pen);

		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);
	

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_ax,lim_ayy, lim_axx,lim_ayy);

	
	

	}
	else {	
		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);
	}



/////////////////////////////////////////////////////////////////////
	lim_ax = coord_circle_1.x - ((min_d/2)*sqrt(2));
	lim_ay = coord_circle_1.y - ((min_d/2)*sqrt(2));
	lip_ax = coord_circle_1.x + ((min_d/2)*sqrt(2));
	lip_ay = coord_circle_1.y + ((min_d/2)*sqrt(2));

	lim_axx = coord_circle_3.x - ((min_d/2)*sqrt(2));
	lim_ayy = coord_circle_3.y - ((min_d/2)*sqrt(2));
	lip_axx = coord_circle_3.x + ((min_d/2)*sqrt(2));
	lip_ayy = coord_circle_3.y + ((min_d/2)*sqrt(2));
//////////////////////////////////////////////////////
	lf_ax = coord_circle_1.x - coord_circle_3.x;
	lf_ay = coord_circle_1.y - coord_circle_3.y;

	lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
/////////////////////////////////////////////////////

	if (lf_absa>=min_d){
		dc.SelectObject(&pen);

		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);
	

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_ax,lim_ayy, lim_axx,lim_ayy);

	}
	else {	
		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);
	}

/////////////////////////////////////////////////////////////////////
	lim_ax = coord_circle_1.x - ((min_d/2)*sqrt(2));
	lim_ay = coord_circle_1.y - ((min_d/2)*sqrt(2));
	lip_ax = coord_circle_1.x + ((min_d/2)*sqrt(2));
	lip_ay = coord_circle_1.y + ((min_d/2)*sqrt(2));

	lim_axx = coord_circle_4.x - ((min_d/2)*sqrt(2));
	lim_ayy = coord_circle_4.y - ((min_d/2)*sqrt(2));
	lip_axx = coord_circle_4.x + ((min_d/2)*sqrt(2));
	lip_ayy = coord_circle_4.y + ((min_d/2)*sqrt(2));
//////////////////////////////////////////////////////
	lf_ax = coord_circle_1.x - coord_circle_4.x;
	lf_ay = coord_circle_1.y - coord_circle_4.y;

	lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
/////////////////////////////////////////////////////

	if (lf_absa>=min_d){
		dc.SelectObject(&pen);

		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);
	

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_ax,lim_ayy, lim_axx,lim_ayy);

	}
	else {	
		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);
	}
	
	/////////////////////////////////////////////////////////////////////
	lim_ax = coord_circle_2.x - ((min_d/2)*sqrt(2));
	lim_ay = coord_circle_2.y - ((min_d/2)*sqrt(2));
	lip_ax = coord_circle_2.x + ((min_d/2)*sqrt(2));
	lip_ay = coord_circle_2.y + ((min_d/2)*sqrt(2));

	lim_axx = coord_circle_3.x - ((min_d/2)*sqrt(2));
	lim_ayy = coord_circle_3.y - ((min_d/2)*sqrt(2));
	lip_axx = coord_circle_3.x + ((min_d/2)*sqrt(2));
	lip_ayy = coord_circle_3.y + ((min_d/2)*sqrt(2));
//////////////////////////////////////////////////////
	lf_ax = coord_circle_2.x - coord_circle_3.x;
	lf_ay = coord_circle_2.y - coord_circle_3.y;

	lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
/////////////////////////////////////////////////////

	if (lf_absa>=min_d){
		dc.SelectObject(&pen);

		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);
	

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_ax,lim_ayy, lim_axx,lim_ayy);

	}
	else {	
		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);
	}

	/////////////////////////////////////////////////////////////////////
	lim_ax = coord_circle_2.x - ((min_d/2)*sqrt(2));
	lim_ay = coord_circle_2.y - ((min_d/2)*sqrt(2));
	lip_ax = coord_circle_2.x + ((min_d/2)*sqrt(2));
	lip_ay = coord_circle_2.y + ((min_d/2)*sqrt(2));

	lim_axx = coord_circle_4.x - ((min_d/2)*sqrt(2));
	lim_ayy = coord_circle_4.y - ((min_d/2)*sqrt(2));
	lip_axx = coord_circle_4.x + ((min_d/2)*sqrt(2));
	lip_ayy = coord_circle_4.y + ((min_d/2)*sqrt(2));
//////////////////////////////////////////////////////
	lf_ax = coord_circle_2.x - coord_circle_4.x;
	lf_ay = coord_circle_2.y - coord_circle_4.y;

	lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));
/////////////////////////////////////////////////////

	if (lf_absa>=min_d){
		dc.SelectObject(&pen);

		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);
	

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_ax,lim_ayy, lim_axx,lim_ayy);

	}
	else {	
		dc.Arc(lim_ax,lim_ay ,lip_ax,lip_ay,lim_ax,lim_ay, lim_ax,lim_ay);

		dc.Arc(	lim_axx,lim_ayy,lip_axx,lip_ayy,lim_axx,lim_ayy, lim_axx,lim_ayy);
	}

	}
						
}			

/*
	CPaintDC dc(this);
    CBrush brush;
 
    brush.Attach(GetStockObject(NULL_BRUSH));
 
    dc.SelectObject(brush);
    dc.Arc(0,0,150,150, 0,0, 10, 10);
    dc.Ellipse(10, 10, 200, 200);
    brush.DeleteObject();
	*/




	void additional_function(int *lpi_TWO_pointCounter,int *size ,Point *fpp_pointCounter){
	int li_max_x,li_max_x_ind,li_i;

	Point *lp_begin,lp_tmp ;

		lp_begin=fpp_pointCounter;
		li_max_x=lp_begin->x;
		li_max_x_ind=0;
			for(li_i=0;li_i<*size;li_i++,lp_begin++){
				if (li_max_x<lp_begin->x){
					li_max_x=lp_begin->x;
					li_max_x_ind=li_i;}
			
			}

		lp_tmp=*(fpp_pointCounter);
		*(fpp_pointCounter)=*(fpp_pointCounter+li_max_x_ind);
		*(fpp_pointCounter+li_max_x_ind)=lp_tmp;



		lp_begin=(fpp_pointCounter+1);
		li_max_x=lp_begin->x;
		li_max_x_ind=0;
			for(li_i=1;li_i<*size;li_i++,lp_begin++){
					if (li_max_x<lp_begin->x){
						li_max_x=lp_begin->x;
						li_max_x_ind=li_i;}
					
					}
			lp_tmp=*(fpp_pointCounter+1);
			*(fpp_pointCounter+1)=*(fpp_pointCounter+li_max_x_ind);
			*(fpp_pointCounter+li_max_x_ind)=lp_tmp;
				
		
	}


/*	CPen* oldPen ;
		CPen pen(PS_SOLID,1,RGB(200,5,0));       
dc.SelectObject(&pen);*/


		/*	max_d=0;	
	

		min_d = 100000;

		for (li_i=0;li_i<number_diagonals;li_i++ ){
			k=li_i+2;
				for (li_j=0;li_j<number_diagonals/2; li_j++ ,lpp_continue++){
					if (li_beg == li_i && li_i!=0){continue;}

					

						
					
			
					
					lf_ax = lpp_continue->x - lpp_begin->x; 
					lf_ay = lpp_continue->y - lpp_begin->y;
					lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));

					

					if (max_d<lf_absa){
						max_d=lf_absa;
						max_d_ind = k;}
						
						if(min_d > lf_absa)
							min_d = lf_absa;

				}		

				lpp_begin++;
			
				array_diagonals[li_i] = max_d;

				lpp_continue=(lpp_begin+2);

				arr_ind_d[li_bla]=li_i;
				li_bla++;

				arr_ind_d[li_bla]=max_d_ind;
				li_bla++;
				max_d=0;
		}
	
	for (li_i=0;li_i<number_diagonals;li_i++ ){
	if (max_d<array_diagonals[li_i])
		max_d=array_diagonals[li_i];
	continue;}

	for (li_i=0;li_i<number_diagonals;li_i++ ){
	k = array_diagonals[li_i];
	continue;}



		max_d=array_diagonals[0];
	for (li_i=0;li_i<number_diagonals;li_i++ )	
		if (max_d<array_diagonals[li_i]){
			max_d=array_diagonals[li_i];
			max_d_ind=li_i;
		}*/

///////////////////////////////////////////////////////////

		/*	for(li_i=0;li_i<size;li_i++,lpp_begin++){

		for (li_j=0;li_j<size;li_j++,lpp_continue++){
		
					lf_ax = lpp_continue->x - lpp_begin->x; 
					lf_ay = lpp_continue->y - lpp_begin->y;
					lf_absa = sqrt(abs(lf_ax) * abs(lf_ax) + abs(lf_ay) * abs(lf_ay));

			arr[li_bla].p1 = *lpp_begin;
			
			arr[li_bla].p2 = *lpp_continue;
			
			arr[li_bla].abs = lf_absa;
			li_bla++;


		}
		lpp_continue=(pointCounter);
		
	}*/
		