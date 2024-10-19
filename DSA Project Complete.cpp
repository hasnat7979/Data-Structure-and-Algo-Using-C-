#include<iostream>
#include<queue>
using namespace std;

class DSA_proj{
	public:int size=0,item,N=0, bubblesort,num,k;
	int lb=0;//variables of arrays
	int*A,*left,*right;                      //pointer of arrays
	int*S;                                  // pointer For Stack
	int choice , sorttype, searchtype, count=0, sitem;          //variables of arrays
	struct Node{
		public:	int info, height=0;
                Node*prev;    // for LL
                Node*next;   // for LL
				Node*root;   // for tree
		        Node*left;   // for tree
		        Node*right;	
	};
	struct Node_AVL{
		int info;
 		int height;
 		Node_AVL*Left,*Right;
		};
	Node_AVL *Root;					
	Node*ptr=start;
	Node*start=NULL;
	Node*TOP=NULL;          //For stack on Single linked list
	Node*TOP_DLL=NULL;   	//For Stack Double linked list 
	int Top=lb-1;       	//For Stack On Array 
	int*Q;               	//pointer for Queue  
	int FA,RA;
	Node*F=NULL,*R=NULL;    //For Queue On linked List  
	Node*root=NULL;         //FOR TREE
	int H[50];
		//int size = 0;     //for heap             //for heap
	int parent(int i){
		    return i / 2;   
		}                
	DSA_proj(){
		cout<<"\t\t\tDATA STRUCTURE AND ALORITHUM\n\n";
		cout<<"\t\t\tCLASS : BSCS 3RD\n";
		cout<<"\t\t\tNAME  : ROZEENA KHALID\n";
		cout<<"\t\t\tMISID : \n\n ";
		cout<<"\t\t\tDSA LAB PROJECT\n\n";
		cout<<"1)DATA STRUCTURE OF AN ARRAY\n";
		cout<<"2)DATA STRUCTURE OF LINKED LIST\n";
		cout<<"3)DATA STRUCTURE OF STACK\n";
		cout<<"4)DATA STRUCTURE OF QUEUE\n";
		cout<<"5)DATA STRUCTURE OF TREE\n";
		cout<<"6)Exit program\n";
		cout<<"Enter your choice\n";
		cin>>num;
		switch(num){
			case 1:{
				ARRAYS();
			}
			break;
			case 2:{
				LINKEDLIST();
			}
     		break;
    		case 3:{
				STACK();
			}
      		break;
    		case 4:{
				QUEUE();
			}
     		break; 
			case 5:{
				TREE();
			}
	 		break;
			case 6:{
				cout<<"Exiting program";
	          	exit(0);
			}
			break;
			default:{
				cout<<endl<<"invalid selection";
			}}}
		void ARRAYS(){ 
		system("cls");
   		cout<<"DATA STRUCTURE OF ARRAYS\n\n"<<endl;
		cout<<"Enter the size of Array";
		cin>>size;
		A = new int[size];
		int choice;
	    while(true)
			{
 			cout<<endl<<"\nKindly Enter your Choice:\n\n"
						"1)Press 1 for Traverse\n" 
						"2)Press 2 for Insertion\n"
						"3)Press 3 for Deletion\n"
						"4)Press 4 for Searching\n"
						"5)Press 5 for Sorting\n"
						"6)Press 6 for Merging\n"
						"7)Press 7 for Return to Main menu\n"
						"8)Press 8 for exit"; 
			cin>>choice;
			switch(choice)
				{
				case 1:{
					Traverse();
				} 	
				break;
				case 2:{
					Insertion();
				}     
				break;
				case 3:{
					Deletion();
				}     
				break;
				case 4:{
					Searching();
				}     
				break;
				case 5:{
					Sorting();
				}    
				break;
				case 6:{
					Merging();
				}
				break;
				case 7:{
					DSA_proj();
				}     
				break;
				case 8:{	
					cout<<"Exiting Program";
			    	exit(0); 
				}
		 		default:{
					cout<<endl<<"Invalid Selection";
				 }}}} 

// Methods
void Traverse(){
		if(N==0){
			cout<<endl<<"Array is empty";
			return; 
		}
		cout<<endl<<"Array is given:";
		for(int i=0; i<=(N+lb-1); i++){
			cout<<endl<<"["<<A[i]<<"]"<<endl;
		}
	}

void Insertion(){
		cout<<endl<<"Enter the value you want to insert:";
		cin>>item;
		if(N==size){
			cout<<endl<<"Array is already full";
			return;
			}
		cout<<endl<<"Enter the position in which you want to insert the element:";
		cin>>k;
		if((k<lb) || (k>(N+lb))){
			cout<<endl<<"Invalid Selection";
			return;
		}
       else{ 
	   		for(int i=(N+lb-1); i>=k; i--)
			{
				A[i+1]=A[i];
			}
				A[k]=item;
				N++;
		}
		cout<<endl<<"Insertion Completed";	
	}

void Deletion(){	
	if(N==0){
		cout<<endl<<"Array is Empty";
		return;	
		}
	cout<<endl<<"Enter position of value you want to delete";
	cin>>k;
	if((k<lb)||(k>(N+lb-1))){
            cout<<endl<<"You have choosed invalid postion";
            return;
        }
		else{
            item=A[k];
            for(int i=(k+1); i<=(N+lb-1); i++){
                A[i-1]=A[i];  
			}
            N--;
            cout<<endl<<"Deletion Completed";
		}
    }
void Searching(){   
        if(N==0){
            cout<<endl<<" Array is empty";
            return;
		}
        cout<<endl<<"Press 1 for single Search\n"
            		"Press 2 for multi Search";
        cin>>searchtype;
        switch(searchtype){
            case 1:{
				Singlesearching();
			}
			break;
            case 2:{
				Multisearching();
			}     
            break;
            default:{
				cout<<endl<<"Invalid search type";
			}
		}
	}
void Singlesearching(){
    	cout<<endl<<"Enter  value which you want to search for\n";
        cin>>item;
		cout<<endl<<"Choose your operation\n"
					"1)Linear Searching\n"
					"2)Binary Searching\n";
		cin>>searchtype;
		switch(searchtype){
			case 1:{	
				for(int i=lb; i<=(N+lb-1); i++){
                if(A[i]==item){
                        cout<<endl<<item<<" item Found";
                    	return;
					}
				}
            cout<<endl<<item<<" item not Found";
			}
			break;
			case 2:{
				bubblesort=1;
				Bubblesort();
				int low=lb;
				int high=(N+lb-1);
				int mid;
				while(low<=high){
					mid=(low+high)/2;
						if(A[mid]==item){
							cout<<endl<<item<<"item found";
							return;
						}
						else if(A[mid]>item){
							high=mid-1;  
						}
						else{   	
							low=mid+1;                  
						}
				}
		        cout<<endl<<item<<" item not found";
			}
			break;				
			default:{
			cout<<"Invalid Selection";
			}
		}
	}
void Multisearching(){
		cout<<endl<<"Enter value which you want to search for";
    	cin>>item;
		int count=0;
		cout<<endl<<"Choose your operation\n"
					"1)Linear Searching\n"
					"2)Binary Searching\n";
		cin>>searchtype;
		switch (searchtype){
			case 1:{  
				for(int i=lb; i<=(N+lb-1); i++){
                if(A[i]==item){
                    count+=1;
				    }
				}
            if(count==0){
                cout<<endl<<item<<"item not found";
            	return;  
				}
       		else{   
			   	cout<<endl<<item<<"item found "<<count<<" times";
				}
			}
			break;
			case 2:{
				bubblesort=1;
				Bubblesort();
				int low=lb, high=(N+lb-1);
				int mid;
				while(low<=high){
					mid=(low+high)/2;
						if(A[mid]==item){
							count++;
							int i=mid-1;
							while((i>=lb)&&(A[i]==item)){
								count++;
								i--;
							}
						 	i=mid+1;
							while ((i<(N+lb))&&(A[i]==item)){
								count++;
								i++;
							}
							cout<<endl<<item<<" found "<<count<<" times.";
							return;
						}
						else if(A[mid]>item){
							high=mid-1;
						}
						else{
							low=mid+1;
						}
					}
				cout<<endl<<"item not found"; 
			}
			break;
			default:{
				cout<<"Invalid Selection";
			}
		}
	}
void Sorting(){  	
		if(N==0){   
			cout<<endl<<"You have nothing to sort as an array is empty";
	        return;
		}
		cout<<endl<<"select your sort type\n"
					"1)Press 1 for Bubblesort\n"
					"2)Press 2 for Selectionsort\n"
					"3)Press 3 for Inerstionsort\n"
					"4)Press 4 for Shellsort\n"
					"5)Press 5 for Mergesort\n"
					"6)Press 6 for Quicksort\n"
					"7)Press 7 for return to arrays main menu\n";
		cin>>sorttype;
		switch (sorttype){
			case 1:{
				Bubblesort();
			}	    
			break;
			case 2:{
				Selectionsort();
			}         
			break;
			case 3:{
				Insertionsort();
			}      	
			break;
			case 4:{
				Shellsort();
			}    	
			break;
	    	case 5:{
				Mergesort();
			}         
			break;
			case 6:{
				Quicksort();
			}         
			break;
			case 7:{
				ARRAYS();
			}         
		    break;
			default:{
				cout<<endl<<"Invalid Selection";
			}
		}
	}
void Bubblesort(){
		cout<<endl<<"Enter the value which you want to bubble sort for in ascending order ";
		cin>>item;
		for(int i=0; i<(N-1); i++){
			int last=(N+lb-1);
					for(int j=lb; j<=(last-1); j++){
						if(A[j]>A[j+1]){
								A[j] = A[j]+A[j+1];
							    A[j+1] = A[j]-A[j+1];
							    A[j] = A[j]-A[j+1];
							}
						}
					}
			cout<<endl<<"Bubblesorting in ascending order completed";  
		}
void Selectionsort(){
		int j;
		int first=0;
		int lb=first;
		for(int i=0; i<(N-1); i++){
			int min=first;
				for( j=first; j<=(N+lb-1); j++){ 
				if(A[min]>A[j]){
					min=j;
					}
				}
		A[lb] = A[lb]+A[j];		
		A[j] = A[lb]-A[j];	
		A[lb] = A[lb]-A[j];
		}	
	cout<<endl<<"Selectionsorting Completed";
}
void Insertionsort(){
		int last=lb+1;
		for(int j=0; j<(N-1); j++){
			int min=A[last], i=last-1;
		 	while((i>=lb)&&(A[i]>min)){
		 		A[i+1]=A[i];
		 		i=i-1;
			}
		 	A[i+1]=min;
		 	last=last+1;
		}
	cout<<"Insertionsorting Completed";	
}
void Shellsort(){
    	int gap=N/2;
   	  	while(gap!=0){
      	for (int last=lb+gap;last<=N+lb-1; last++){
      	int min=A[last], i=last-gap;
	   	while((i>=lb)&&(A[i]>min)){
			A[i+gap]=A[i];
			i=i-gap;
			}
     	A[i+gap]=min;
		}
        gap=gap/2;
	}
    cout<<"Shellsorting Completed";
}
   void Mergesort(){
   		int low=lb, high=N+lb-1;
   		Mergesort_Sub(low,high);
	}
    void Mergesort_Sub(int low,int high){  if(low<high){
        	int mid=low+high/2;
	        Mergesort_Sub(low,mid);
	        Mergesort_Sub(mid+1,high);
	        Mergings(low,mid,high);
			}
		}
    void Mergings(int low,int mid, int high){
     		int NL=(mid-low+1);
			int NR=high-mid;
			k=lb;
			int Left[NL], Right[NR];
			for(int i=low; i<=mid; i++){
				Left[k]=A[i];
				k++;
			}
	   		k=lb;
			for(int i=(mid+1); i<=high; i++){
				Right[k]=A[i];
				k++;
			}
			int PTRA, PTRL, PTRR;
			PTRL=PTRR=lb;
			PTRA=low;
			while((PTRL<=(NL+lb-1))&&(PTRR<=(NR+lb-1))){
				if(Left[PTRL]<Right[PTRR]){
					A[PTRA]=Left[PTRL];
					PTRL++;
				}
		    else{  
				A[PTRA]=Right[PTRR];
				PTRR++;
			 }
			PTRA++;
		    }
			if(PTRL>(NL+lb-1)){
				for(int i=PTRR; i<=(NR+lb-1); i++){
					A[PTRA]=Right[i];
				  	PTRA++;
				}
			}
	    	else{  
				for(int i=PTRL; i<=(NL+lb-1); i++){
				A[PTRA]=Left[i];
				PTRA++;
				}
			}
			cout<<"Mergesorting Completed";
		}
  void Quicksort(){ 
  		int low=lb,high=N+lb-1;
		Quicksort_sub(low,high);
	}
   void Quicksort_sub(int low,int high){
		if(low<high){
			int index=partition(low,high);
			Quicksort_sub(low,index-1);
			Quicksort_sub(index+1,high);}}
    		int partition(int low,int high){
    			int pivot=A[high];
	    		int i=low-1;
	  			for(int j=low; j<=high-1;j++){
					if(A[j]<=pivot){
					i=i+1;
					int swap=A[i];
					A[i]=A[j]; 
					A[j]=swap;  
					}
				}
		int swap=A[i+1];
		A[i+1]=A[high];
		A[high]=swap;
    	return(i+1);
		cout<<"Quicksorting Completed";
	}
  void Merging(){
  		int NA, NB;
		cout<<endl<<"Enter size of first Array";
		cin>>NA;
		int Aa[NA];
		cout<<"Enter values in  First Array\n"
		      "Values must be in Ascending Order";
		for(int i=lb; i<NA; i++){
			cin>>Aa[i];
		}
		cout<<endl<<"Enter size of Second Array";
		cin>>NB;
		int B[NB];
		cout<<"Enter values in  Second Array\n"
		       "Values must be in Ascending Order";
		for(int i=lb; i<NB; i++){
			cin>>B[i];
		}
		int NC=NA+NB;
		int C[NC];
		int PTRA, PTRB, PTRC;
		PTRA=PTRB=PTRC=lb;
		while((PTRA<=(NA+lb-1))&&(PTRB<=(NB+lb-1))){
			if(Aa[PTRA]<B[PTRB]){
				C[PTRC]=Aa[PTRA];
				PTRA++;
			}
			else{  
				C[PTRC]=B[PTRB];
				PTRB++;
			}
			PTRC++;
		}
		if(PTRA>(NA+lb-1)){
			for(int i=PTRB; i<=(NB+lb-1); i++){
				C[PTRC]=B[i];
				PTRC++;
			}
		}
		else{  
			for(int i=PTRA; i<=(NA+lb-1); i++){
				C[PTRC]=Aa[i];
				PTRC++;
			}
		}
		cout<<endl<<"Fisrt Array is:";
		for(int i=lb; i<NA; i++){
			cout<<endl<<"["<<Aa[i]<<"]";
		}
		cout<<endl<<"Second Array is:";
		for(int i=lb; i<NB; i++){
			cout<<endl<<"["<<B[i]<<"]";
		}
		cout<<endl<<"Merged Array is:";
		for(int i=lb; i<NC; i++){
			cout<<endl<<"["<<C[i]<<"]";
		}
	}
void LINKEDLIST(){  
        system("cls");
		cout<<"\n\n DATA STRUCTURE OF LINKED LIST\n\n"
            	"Enter Your Choice\n"
				"1)Press 1 for Single Linkedlist\n" 
				"2)Press 2 for Double Linkedlist\n"
				"3)Press 3 for exit\n"; 
			cin>>choice;
			switch(choice){
				case 1:{
					Singlelinkedlist();
				}    
				break;
				case 2:{
					DoubleLinkedList(); 
				}    	
				break;
		    	case 3:{
					cout<<endl<<"exiting Program";
                    exit(0);
				}      
                break;
		    	default:{
					cout<<endl<<"Invalid Selection";
				}
			}
		}
void Singlelinkedlist(){	
			system("cls");
        	cout<<"\n\nSingle LinkedList \n\n";
        	while(true){
            	cout<<endl<<"\nSelect your Choice"
             				"\n1) Press 1 for Traverse_SLL"
            				"\n2) Press 2 for Searching_SLL"
				            "\n3) Press 3 for Insertion_SLL"
							"\n4) Press 4 for Deletion_SLL";
				cin>>choice;
            	switch(choice){
                case 1:{
					Traverse_SLL();
				}    
            	break;
                case 2:{
					Searching_SLL();
				}    
                break;
                case 3:{
					Insertion_SLL();
				}   
                break;
                case 4:{
					Deletion_SLL();
				}    	
		        break;
                default:{
					cout<<endl<<"Invalid Selection";
					break;
				} 
			}
		}
	}
   	void Traverse_SLL(){
        Node*ptr=start;
		if(ptr==NULL){
			cout<<"Linkedlist is Empty";
		}
		while(ptr!=NULL){
			cout<<"\t["<<ptr->info<<"]";
			ptr=ptr->next;
		}
		ptr=NULL;
		delete(ptr);
	}
void Searching_SLL(){
		cout<<"\nSelect option"
	        "\n1)Press 1 for Singlesearch"
	        "\n2)Press 2 for Multisearch";
	        cin>>choice;
	        switch(choice){
            	case 1:{
					SingleSearch_SLL();
				}  
	            break;
	            case 2:{
					MultiSearch_SLL();
				}  
	            break;
	            default:{
					cout<<"\nInvalid Selection";
					break;
				} 
	        }
		}
void SingleSearch_SLL(){
		cout<<"\nEnter value that you want to seach";
        cin>>sitem;
	    Node*ptr=start;
	    while(ptr!=NULL){
			if(ptr->info==sitem){
			    cout<<"item Found";
				ptr=NULL;
                delete(ptr);
                return;
			}
            ptr=ptr->next;}
		    cout<<"item Not Found";
	     	ptr=NULL;
            delete(ptr);
		}
void MultiSearch_SLL(){
        cout<<"\nEnter value that you want to search";
        cin>>sitem;
        Node* ptr=start;
        int count=0;
        while(ptr != NULL){
            if(ptr->info == sitem){
                count++;
			}
          ptr=ptr->next;
		}
        if(count==0){
            cout<<"\n item not Found";
		}
        else{  
			cout<<endl<<sitem<<" found "<<count<<" times";}
        	ptr=NULL;
        	delete(ptr);
		}
void Insertion_SLL(){
        while(true){
        cout<<"\nSelect desired Option"
		        "\n1) Press 1 for Insertion at First"
		        "\n2) Press 2 for Insertion at Last"
		        "\n3) Press 3 for Insertion at Middle"
		        "\n4) Press 4 for return";
        cin>>choice;
        switch (choice){
	        case 1:{
				Insertion_At_First_SLL();
			}  
	        break;
	        case 2:{
				Insertion_At_Last_SLL();
			}  
			break;
	        case 3:{
				Insertion_Middle_SLL();
			}  
	        break;
	        case 4:{
				Singlelinkedlist();
			}  
			break;
	        default:{
				cout<<"\nInvalid Selection";
				break;
			}  
	    }
	}
}
void Insertion_At_First_SLL(){
        cout<<"\nEnter value you want to insert";
        cin>>item;
        Node*ptr=new Node;
        ptr->info=item;
        ptr->next=start;
        start=ptr;
        cout<<"Insertion at first is completed";
        ptr=NULL;
        delete(ptr);
	}
void Insertion_At_Last_SLL(){
   	    cout<<"\nEnter value you want to insert";
        cin>>item;
        Node*ptr= new Node;
        ptr->info=item;
        ptr->next=NULL;
        if(start==NULL){
        	start=ptr;
		}
		else{	
			Node*ptr1=start;
			while((ptr->next)!=NULL){
				ptr1=ptr1->next;
			}
			ptr1->next=ptr;
			ptr1=NULL;
        	delete(ptr1);
		}
		cout<<"\nInsertion at Last Completed";
        ptr=NULL;
        delete(ptr);	
	}
void Insertion_Middle_SLL(){
   		cout << "Press\n"
                "1 for Insertion at  given node\n"
                "2 for Insertion at exactly middle node\n";
        cin >> choice;
        switch (choice){
        	case 1:{
				Insertion_At_GivenNode_SLL();
			}    
        	break;
        	case 2:{
				Insertion_At_ExactlyMid_SLL();
			}    
        	break;
        	default:{
				cout<<"Invalid Selection\n";
			}   
        	break;
		}
	}
void Insertion_At_GivenNode_SLL(){
        cout << "Press\n"
                "1 for Insert Before Given node\n"
                "2 for Insert After Given node\n";
        cin >> choice;
        switch (choice){
	        case 1:{
				Insertion_Before_GivenNode_SLL();
			}   
	        break;
	        case 2:{
				Insertion_After_GivenNode_SLL();
			}   
	        break;
	        default:{
				cout << "Invalid Selection\n";
	            break;
			}
		}
	}
void Insertion_Before_GivenNode_SLL(){
	 	cout<<"\nEnter value before which you want to insert a Node";
        cin>>sitem;
        if(start==NULL){
        	cout<<"item not Found";
        	return;
		}
	    Node*ptr1=start;
	  	if(ptr1->info==sitem){
		 	cout<<"\nEnter the value you want to insert";
	        cin>>item;
		 	Node*ptr=new Node;
		 	ptr->info=item;
		 	ptr->next=start;
		 	start=ptr;
		 	cout<<"\nInsertion Completed Before given Node";
	        ptr=NULL;
	        delete(ptr);
	        return;
		}
	 	while((ptr1->next!=NULL)&&(ptr1->next->info!=sitem)){
	 		ptr1=ptr1->next;}
	 		if(ptr1->next==NULL){
		 		cout<<"Element Not Found";
		 		ptr1=NULL;
		 		delete(ptr1);
		 		return; 
			}
		cout<<"\nEnter the value you want to insert";
        cin>>item;
		Node*ptr=new Node;
		ptr->info=item;
		ptr->next=ptr1->next;
		ptr1->next=ptr;
		cout<<"Insetion Is Completed";
		ptr=NULL;
		delete(ptr);
		ptr1=NULL;
		delete(ptr1);
	} 
void Insertion_After_GivenNode_SLL(){
	 	cout<<"\nEnter value after which you want to insert a Node";
        cin>>sitem;
        Node* ptr1=start;
        while((ptr1!=NULL) && (ptr1->info != sitem)){
            ptr1=ptr1->next;
		}
        if(ptr1==NULL){
        	cout<<"Given item is not found";
        	ptr1=NULL;
            delete(ptr1);
            return;
		}
		cout<<"\nEnter the value you want to insert";
        cin>>item;
        Node*ptr=new Node;
        ptr->info=item;
        ptr->next=ptr1->next;
        ptr1->next=ptr;
        cout<<"\nInsertion completed After a given Node";
        ptr=NULL;
        delete(ptr);
        ptr1=NULL;
        delete(ptr1);
	}
void Insertion_At_ExactlyMid_SLL(){
	    cout << "Press\n"
                "1 for Insert Before Mid node\n"
                "2 for Insert After Mid node\n";
        cin>>choice;
        switch(choice){
			case 1:{
				Insert_Before_Exact_Mid_SLL();
			}  
	        break;
	        case 2:{
				Insert_After_Exact_Mid_SLL();
			}   
	        break;
	        default:{
				cout << "Invalid Selection\n";
	        	break;  
			} 
		}
	}
void Insert_Before_Exact_Mid_SLL(){
    Node*ptr=new Node();
   	cout<<"Insert item: ";
   	cin>>item;
   	ptr->info=item;
   	Node*ptr1=start;
   	int count=0;
   	while(ptr1!=NULL){
	   	count++;
   		ptr1=ptr1->next;
	}
	if((count==0)||(count==1)){
		ptr->next=start;
		start=ptr;
		cout<<item<<" is inserted";
		return;
	}
	int mid=(count/2)+1;
	ptr1=start;
	for(int i=0;i<(mid-2);i++){
		ptr1=ptr1->next;
	}
	  ptr->next=ptr1->next;
	  ptr1->next=ptr;
	  cout<<item<<" is inserted";
	}
void Insert_After_Exact_Mid_SLL(){
   	Node*ptr=new Node();
   	cout<<"Insert an item: ";
   	cin>>item;
   	ptr->info=item;
   	int count=0;
   	Node*ptr1=start;
   	while(ptr1!=NULL){
	    count++;
   		ptr1=ptr1->next;
	}
	if(count==0){
		ptr->next=NULL;
		start=ptr;
		cout<<item<<" Inserted";
		return;
	}
	int mid=(count/2)+1;
	ptr1=start;
	for(int i=0;i<(mid-1);i++){
		ptr1=ptr1->next;
	}
	if((count==1)||(count==2)){
		ptr->next=NULL;
		ptr1->next=ptr;
		cout<<item<<" Inserted";
		return;
	}
	  ptr->next=ptr1->next;
	  ptr->next=ptr1;
	  cout<<item<<"Inserted"<<endl;
	}
void Deletion_SLL(){
    	system("cls");
		cout<<"Select Your Choice\n"
	          "1)Press 1 for Deletion At First\n"
	      	  "2)Press 2 for Deletion At Last\n"
		      "3)Press 3 for Deletion At middle";
		cin>>choice;
		switch(choice){
			case 1:{
				Deletion_AtFirst_SLL();
			} 		
			break;
			case 2:{
				Deletion_AtLast_SLL();
			}     
			break;
			case 3:{
				Deletion_AtMiddle_SLL();
			}     
			break;
			case 4:{
				Singlelinkedlist();
			}      
			break;
			default:{
				cout<<"Invalid Seletion\n";
				break;
			}    
		}
	}
void Deletion_AtFirst_SLL(){
     	if(start==NULL){
			cout<<"Linked list is empty";
			return;
		}
		Node*ptr=start;
		start=start->next;
		delete(ptr);
		cout<<"Deletion At First completed";
	}
void Deletion_AtLast_SLL(){
    	if(start==NULL){
			cout<<"Linked list is Empty";
			return;
		}
	if(start->next==NULL){
		start=NULL;
		return;
	}
	Node*ptr=start;
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	  delete(ptr);
	  ptr->next=NULL;
	}
Deletion_AtMiddle_SLL(){
	 cout << "Press\n"
                "1 for Deletion at  given node\n"
                "2 for Deletion at exactly middle node\n";
        cin >> choice;
        switch (choice){
        case 1:{
			Deletion_At_GivenNode_SLL();
		}    
        break;
        case 2:{
			Deletion_At_ExactlyMid_SLL();
		}    
        break;
        default:{
			cout << "Invalid Selection\n";
        	break;
		}   
	}
}
void Deletion_At_GivenNode_SLL(){
      	if(start==NULL){
	      	cout<<" Linked list Is Empty\n";
	      	return; 
		} 
	  	cout<<"\nEnter the value you want to delete";
        cin>>sitem;
     	if((start->info)==sitem){
			Node*ptr=start;
		    start=start->next;
		    ptr=NULL;
		    delete(ptr);
		    return; 
		}
	    Node* ptr=start;
	    while((ptr->next!=NULL)&&(ptr->next->info!=sitem) ){
	    	ptr=ptr->next; 
		}
	    if(ptr->next==NULL){
			cout<<"Given value not found";
			return;
		} 
		Node*ptr1=ptr->next;
		ptr->next=ptr1->next;
		ptr1=NULL;
		delete(ptr1);
	}
void  Deletion_At_ExactlyMid_SLL(){
    if(start==NULL) {
   		cout<<" Single Linked list is Empty\n";
   		return; 
	} 
	if(start->next==NULL){
		Node*del=start;
			start=NULL;
		delete(start);
		return;
	}
	int count=0;
	Node*ptr=start;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	int mid=(count/2);
	ptr=start;
	for(int i=0; i<(mid-1);i++){
		ptr=ptr->next;
	}
	Node*ptr1=ptr->next;
	ptr->next=ptr1->next;
    ptr1=NULL;
    delete(ptr1);
    ptr=NULL;
  	delete(ptr);
}    
void DoubleLinkedList(){
      	system("cls");
    	cout<<	" \nDouble LinkedList \n";
    	while (true)
        {    
			cout <<"1)Press 1 for Traverse\n"
                   "2)Press 2 for Insertion\n"
                   "3)Press 3 for Deletion\n"
                   "4)Press 4 for exit\n";
            cin >> choice;
            switch (choice) {
            case 1:   Traverse_DLL();
			break;
            case 2:   Insertion_DLL();
            break;
            case 3:   Deletion_DLL();
			break;
            case 4:   cout << "exiting Program";
                exit(0);
            break;
            default:  cout << "Invalid Selection\n";
			}
		}
	}			     
void Traverse_DLL(){
      	ptr = start;
        cout << "List is\n";
        while (ptr != NULL){
			cout << "[" << ptr->info << "]\t";
            ptr = ptr->next;
		}
	}
void Insertion_DLL(){
    while (true) {   
		cout << "1)Press 1 for Insertion at first\n"
                "2)Press 2 for Insertion at Last\n"
                "3)Press 3 for Insertion at Middle\n"
                "4)Press 4 for return\n";
            cin >> choice;
            switch (choice){
	            case 1:  Insertion_AtFirst_DLL();
	            break;
	            case 2:  Insertion_AtLast_DLL();
	            break;
	            case 3:  Insertion_AtMiddle_DLL();
	            break;
	            case 4:   return;
	            break;
	            default:  cout << "Invalid Selection\n";  }
				}
			}
void Insertion_AtFirst_DLL(){
    	cout << "Enter value you want to insert\n";
        cin >> item;
        Node*ptr = new Node();
        ptr->info = item;
        ptr->next = start;
        ptr->prev = NULL;
        if (start != NULL){ 
			start->prev = ptr; 
		}
        start = ptr;
        cout << "Insertion  at first Completed\n";
	}
void Insertion_AtLast_DLL(){
		cout << "Enter value you want to insert\n";
        cin >> item;
        Node *ptr = new Node();
        ptr->info = item;
        ptr->next = NULL;
      	if (start != NULL){
		  	Node *ptr1 = start;
            while (ptr1->next != NULL){
				ptr1 = ptr1->next;
			}
            ptr1->next = ptr;
            ptr->prev = ptr1;
		}
       else{
	   		ptr->prev = NULL;
            start = ptr; 
		}
        cout << "Insertion at last Completed\n";
	}
void Insertion_AtMiddle_DLL(){
		cout <<"1)Press 1 for Insertion by  given node\n"
               "2)Press 2 for Insertion by exactly middle node\n";
        cin >> choice;
        switch (choice){
	        case 1:    Insertion_Mid_Given_Node_DLL();
	        break;
	        case 2:    Insertion_Exactly_Mid_DLL();
	        break;
	        default:   cout << "Invalid Selection\n";
	            break;
			}
		}
void Insertion_Mid_Given_Node_DLL(){
	  	cout <<"1)Press 1 for Insert Before Given node\n"
               "2)Press 2 for Insert After Given node\n";
        cin >> choice;
        switch (choice){
	        case 1:        Insertion_Before_Node_DLL();
	            break;
	        case 2:        Insertion_After_Node_DLL();
	            break;
	        default:       cout << "Invalid Selection\n";
	            break;
			}
		}
void  Insertion_Before_Node_DLL(){
        cout << "Enter item Before which you want to insert a Node";
        cin >> sitem;
        if (start == NULL){ 
			cout << "Element not found\n";
            return;
		}
        if (start->info == sitem){
			cout << "Enter value you want to insert\n";
            cin >> item;
            Node*ptr = new Node();
            ptr->info = item;
            ptr->prev = NULL;
            ptr->next = start;
            start->prev = ptr;
            start = ptr;
            return;
		}
        Node *ptr1 = start;
        while ((ptr1 != NULL) && (ptr1->info != sitem)){
			ptr1 = ptr1->next;
		}
        if (ptr1 == NULL){
			cout << "\nItem not found";
            return;
		}
        cout << "Enter value you want to insert\n";
        cin >> item;
        Node*ptr = new Node();
        ptr->info = item;
        ptr->prev = ptr1->prev;
        ptr1->prev->next = ptr;
        ptr1->prev = ptr;
        ptr->next = ptr1;
	}
void  Insertion_After_Node_DLL(){ 
	    cout << "Enter the item Before which you want to insert a Node";
        cin >> sitem;
    	if(start==NULL){
    	 	cout<<"Linked List is empty";
    	 	return;
		}
		Node*ptr1=start;
		while((ptr1!=NULL)&&(ptr1->info!=sitem)){
		 	ptr1=ptr1->next; 
		}
		if(ptr1==NULL){
			cout << "\nItem not found";
            return;   
		}
        cout << "Enter value you want to insert\n";
        cin >> item;
        Node*ptr = new Node();
        ptr->info = item;
        ptr->next=ptr1->next;
        ptr1->next=ptr;
        ptr1->next->prev=ptr;
		ptr->prev=ptr1;       
    }
void Insertion_Exactly_Mid_DLL() {
	  	cout <<"1)Press 1 for Insert Before Middle node\n"
               "2)Press 2 for Insert After Middle node\n";
        cin >> choice;
        switch (choice) {
	        case 1:    Insertion_Before_Exact_Mid_DLL();
	        break;
	        case 2:    Insertion_After_Exact_Mid_DLL();
	        break;
	        default:   cout << "Invalid Selection\n";
	        break;
		}
	}
		
void Insertion_Before_Exact_Mid_DLL(){
		Node*ptr = new Node();
	    cout << "Enter value you want to insert\n";
  		ptr->info = item;
  		cin >> item;
   		if ((start == NULL) || (start->next == NULL)){
	    ptr->next = start;
	    ptr->prev = NULL;
  		if (start != NULL){
		  	start->prev = ptr;
		}
	   	start = ptr;
	    return;
   		}
    int count=0; 
    Node *ptr1 = start;
    while (ptr1 != NULL){
        count++;
    	ptr1 = ptr1->next;
	}
    int mid = (count / 2) + 1;
    ptr1 = start;
    for (int i = 0; i < mid-2; i++){
        ptr1 = ptr1->next;
	}
    	ptr->next = ptr1->next;
	ptr->prev = ptr1;
	ptr1->next->prev = ptr;
	ptr1->next=ptr;
}
void  Insertion_After_Exact_Mid_DLL(){
     	Node *ptr = new Node();
        cout << "Enter value you want to insert\n";
        cin >> item;
        ptr->info = item;
        if (start == NULL){
			ptr->prev = NULL;
            ptr->next = NULL;
            start = ptr;
            return;
		}
        int count = 0;
        Node *ptr1 = start;
        while (ptr1 != NULL){
			count++;
            ptr1 = ptr1->next;
		}
        int mid = (count / 2) + 1;
        ptr1 = start;
        for (int i = 0; i < mid - 1; i++){
			ptr1 = ptr1->next;
		}
        ptr->prev = ptr1;
        if ((count == 1) || (count == 2)){ 
			ptr->next = NULL;
            ptr1->next = ptr;
            return;
		}
        ptr->next = ptr1->next;
        ptr1->next->prev = ptr;
        ptr1->next=ptr;
	}
void Deletion_DLL(){
	     while (1){
		    cout << "1)Press 1 for Deletion at first\n"
                    "2)Press 2 for Deletion at Last\n"
                    "3)Press 3 for Deletion at Middle\n"
                    "4)Press 4 for return\n";
            cin >> choice;
            switch (choice){
	            case 1:    Deletion_AtFirst_DLL();
	            break;
	            case 2:    Deletion_AtLast_DLL();
	            break;
	            case 3:    Deletion_AtMiddle_DLL();
	            break;
	            case 4:    return;
	            break;
	            default:   cout << "Invalid Selection\n";   
			}
		}
	}
void Deletion_AtFirst_DLL(){
	if(start==NULL){	
		cout<<"Double Linked List is empty";
		return;
	}
	Node*ptr=start;
	start=start->next;
	if(start!=NULL){
		start->prev=NULL;
	}
		delete(ptr);
}
void  Deletion_AtLast_DLL(){
		if(start==NULL){
			cout<<"Double Linked List is empty";
			return;
		}
		if(start->next==NULL){
			Node*ptr=start;
			start=NULL;
			delete(ptr);
			return;
		}
		Node*ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		delete(ptr);
	}
void Deletion_AtMiddle_DLL(){
	   cout << "1)Press 1 for deletion of Given Item\n"
                "2)Press 2 for deletion of Exact Middle\n";
        cin >> choice;
        switch (choice){
	        case 1:  Deletion_At_GivenNode_DLL();
	        break;
	        case 2:  Deletion_At_ExactMid_DLL();
	        break;
	        default:   cout << "Invalid Selection\n";
	        break;
		}
	}
void Deletion_At_GivenNode_DLL(){
	    if(start==NULL){
			cout<<"DoubleLinked List is Empty";
			return;
		}
		cout<<"Enter value you want to delete\n";
		cin>>sitem;
		if(start->info==sitem){
			Node*ptr=start;
			start=start->next;
			if(start!=NULL){
				start->prev=NULL;
			}
				delete(ptr);
			return;
		}
		Node*ptr=start;
		while((ptr!=NULL)&&(ptr->info!=sitem)){
			ptr=ptr->next;
		}
		if(ptr==NULL){
			cout<<"Given Item not Found";
			return;
		}
		Node*ptr1=ptr;
		ptr->prev->next=ptr->next;
		if(ptr->next!=NULL){
			ptr->next->prev=ptr->next;
		}
		delete(ptr1);
	}
void Deletion_At_ExactMid_DLL(){
      if(start==NULL){
			cout<<"Double Linked List Is Empty";
			return;
		}
		if(start->next==NULL){
			Node*ptr=start;
			start=NULL;
			delete(ptr);
			return;
		}
		int count=0;
		Node*ptr=start;
		while(ptr!=NULL){
			count++;
			ptr=ptr->next;
		}
		int mid=(count/2)+1;
		ptr=start;
		for(int i=0;i<(mid-1);i++){
			ptr=ptr->next;
		}
		Node*ptr1=ptr->next;
		if(ptr->next!=NULL){
			ptr1->next=ptr->next;
			ptr->next->prev=ptr1;
		}
		else{
			ptr1->next=NULL;
		}
		delete(ptr);
	}  
void STACK(){
    cout<<"\n\nData structure of stack\n\n";
	cout<<"Enter Your choice\n"
	     "1)Press 1 For Stack on Array\n"
		 "2)Press 2 For Stack on Single Linked list\n"
	 	 "3)Press 3 For Stack on Double Linked List\n"
		 "4)Press 4 For Exit the Program";
	cin>>choice;
	switch(choice){
				case 1:
					Stack_A();
					break;
				case 2:
					Stack_SLL();
					break;
				case 3:
					Stack_DLL();
					break;	
				case 4:
				cout<<"Exiting Program";
			    	exit(0);	
			    default:
			    	cout<<endl<<"Invalid Selection";
				}
			}
void Stack_A(){
  	system("cls");
	cout<<"\n\nStack on Arrays\n\n";
	while(true){
   	 cout<<"1)Press 1 For Push\n"
   	       "2)Press 2 For Pop\n"
   	       "3)Press 3 For Display\n";
   	       "4)Press 4 For Exit\n"
   	       "Enter your choice: ";
   	cin>>choice;
   	switch(choice){
   	case 1:  Push_A();
			break;
	case 2: Pop_A();
			break;
	case 3: Display_A();
			break;
	case 4: exit(0);
			break;
	default: cout<<"Invalid Input"<<endl;
			break;
			}
		}
	}	
void Push_A(){
    cout<<"Enter value you want to insert";
	cin>>item;
    if(Top==size+lb-1){
    	cout<<"Stack is Full"<<endl;
    	return;
	}
   else
      Top++;
      S[Top]=item;
}
void Pop_A(){
	if(Top==lb-1){
       cout<<"Stack is empty"<<endl;
       return;
	}
    item=S[Top];
    Top--;
}
void Display_A(){
    if(Top>=lb-1){
      cout<<"Stack elements are:";
      for(int i=Top; i>=lb; i--)
      cout<<S[i]<<" ";
      cout<<endl;
	}
    else
    cout<<"Stack is empty";
}
void Stack_SLL(){
    system("cls");
	cout<<"\nStack On Single LInked List\n\n";
		while(true){
   			cout<<"1)Press 1 For Push\n"
          		  "2)Press 2 For Pop\n"
       	          "3)Press 3 For Display\n";
    	          "4)Press 4 For Exit"
    	          "Enter your choice: ";
   	cin>>choice;
   	switch(choice)	{
   		case 1:	  PUSH_SLL();	
		   	break;
		case 2:   POP_SLL();
			break;
		case 3:   DISPLAY_SLL();
			break;
		case 4:   exit(0);
			break;
		default:  cout<<"invalid input"<<endl;
			break;
		}
	}
}	
void PUSH_SLL(){
	    Node*ptr=new Node();
	    cout<<"Enter item which you want to insert: ";
	    cin>>item;
	    ptr->info=item;
	    ptr->next=TOP;
		TOP=ptr;
		cout<<item<<" is inserted"<<endl;	
	}
 void POP_SLL(){
	 	if(TOP==NULL){	
		 	cout<<"Stack is empty"<<endl;
	 		return;
		}
		Node*ptr=TOP;
		TOP=TOP->next;
		delete(ptr);
		cout<<"Top item is deleted"<<endl;	 
	}
 void DISPLAY_SLL(){
	if(TOP==NULL){
		cout<<"Stack is empty"<<endl;
		return;
	}
	Node*ptr=TOP;
	cout<<"Stack Linked list is : ";
	while(ptr!=NULL){
		cout<<" ["<<ptr->info<<"]";
		ptr=ptr->next;
	}
	cout<<endl;
}
void Stack_DLL(){
    system("cls");
	cout<<"\nStack On Double Linked List\n\n";
	while(true)	{
   	cout<<"1)Press 1 For Push\n"
          "2)Press 2 For Pop\n"
       	  "3)Press 3 For Display\n";
    	  "4)Press 4 For Exit"
    	   "Enter your choice: ";
   	cin>>choice;
   	switch(choice)	{
   		case 1:	  PUSH_DLL();	
		   	break;
		case 2:   POP_DLL();
			break;
		case 3:   DISPLAY_DLL();
			break;
		case 4:   exit(0);
			break;
		default:  cout<<"invalid input"<<endl;
	 	}
	}
}
void PUSH_DLL(){
	    Node*ptr=new Node();
	    cout<<"Enter item which you want to insert: ";
	    cin>>item;
	    ptr->info=item;
	    ptr->prev=NULL;
	    ptr->next=TOP_DLL;
	    if(TOP_DLL!=NULL){  
			TOP_DLL->prev=ptr;
		}
		TOP_DLL=ptr;
		cout<<item<<" is inserted"<<endl;
	}	
void POP_DLL(){
		if(TOP_DLL==NULL){
			cout<<"Stack is empty"<<endl;
	 		return;
		}
		Node*ptr=TOP_DLL;
		TOP_DLL=TOP_DLL->next;
		if(TOP_DLL!=NULL){  
			TOP_DLL->prev=NULL;
		}
		delete(ptr);
		cout<<"TOP_DLL item is deleted"<<endl;	 
	}
void DISPLAY_DLL(){
	if(TOP_DLL==NULL){
		cout<<"Stack is empty"<<endl;
		return;
	}
	Node*ptr=TOP_DLL;
	cout<<"Stack Linked list is : ";
	while(ptr!=NULL){
		cout<<" ["<<ptr->info<<"]";
		ptr=ptr->next;
	}
	cout<<endl;
}
void QUEUE(){
	system("cls");
	cout<<"\n\nData Structure of Queue\n\n";
	cout<<"Enter Your choice\n"
		  "1)Press 1 For Queue on Array\n"
		  "2)Press 2 For Queue on Single Linked list\n"
		  "3)Press 3 For Queue on Double Linked List\n"
		  "4)Press 4 For Exit the Program";
	cin>>choice;
	switch(choice){
				case 1:  	Queue_A();
					break;
				case 2:     Queue_SLL();
					break;
				case 3:		Queue_DLL();
					break;	
				case 4:{	cout<<"Exiting Program";
			    	exit(0);}
				default:     cout<<endl<<"Invalid Selection";  
				}
			}
void Queue_A(){
	system("cls");
    cout<<" ... Queue On Array ...\n\n";
		int choice;
		cout<<"1)Press 1 for Simple Queue\n" 
	          "2)Press 2 for Circular Queue\n"
		      "3)Press 3 for exit\n"; 
		cin>>choice;
			switch(choice){
			case 1:  	Simple_Queue();
					break;
			case 2:     Circular_Queue();
					break;
			case 3:     cout<<endl<<"Exiting Program";
                    exit(0);
                	break;	
		    default:    cout<<endl<<"Invalid Selection";
			}
		}
void Simple_Queue(){
	cout<<"Enter The Size of Queue";
	cin>>size;
	Q=new int[size];
	FA=lb-1;
    RA=lb-1;
			int option;
			while(true){
			cout<<"Please Enter your choice\n"
				  "1)Press 1 for Insertion\n"
				  "2)Press 2 for Deletion\n"
				  "3)Press 3 for Display\n"
				  "4)Press 4 for Returning to main menu\n";
			cin>>option;
			switch(option){
				case 1:		Simple_Insertion();
					break;
				case 2:		Simple_Deletion();
					break;
				case 3:		Display_SimpleQueue();
						break;
				case 4:    return;
                   break;
				default: cout<<endl<<"Invalid Selection";    
			}
		}
	}
void Simple_Insertion(){
		cout<<"Enter the item you want to insert";
		cin>>item;
		if(RA==size+lb-1){
			cout<<"Simple Queue is Full \n";
			return;
		}
		else if(RA==(lb-1)){
			RA=lb;
			FA=lb;
		}
		else
			RA++;
			Q[RA]=item;
		cout<<"Inserted value is: "<<Q[RA]<<"\n";
	}
void Simple_Deletion() {
	cout<<"Enter the value you want to delete ";
	cin>>item;
	if(FA==lb-1){
		cout<<"Simple Queue is Empty \n";
		return;
	}
	item=Q[FA];
	if(FA==RA){
		RA=lb-1;
		FA=lb-1;
	}
	else{
		FA++;
	}
	cout<<endl<<item<<" has been Deleted from Queue";
}
void Display_SimpleQueue(){
        if(FA==lb-1){
            cout<<"\nQueue is Empty";
            return;
		}
        cout<<"\nQueue is";
        for(int i=FA; i<=RA; i++){
            cout<<"\t["<<Q[i]<<"]";    
		}
	}
void Circular_Queue(){
		cout<<"\n Enter size of you Queue";
        cin>>size;
        Q=new int[size];
        FA=lb-1;
        RA=lb-1;
			int option;
			while(true){
			cout<<"Enter your choice\n"
				  "1)Press 1 for Insertion\n"
				  "2)Press 2 for Deletion\n"
				  "3)Press 3 for Display\n"
				  "4)Press 4 for Returning to main menu\n";
			cin>>option;
			switch(option){
				case 1:     	Simple_Insertion();
					break;
				case 2:     	Simple_Deletion();
					break;
				case 3:      	Display_CircularQueue();
					break;
				case 4:          return;
                    break;
				default:  	cout<<endl<<"Invalid Selection";    
				}
			}
		}
		
void Circular_Insertion(){
	cout<<"Enter the item you want to  insert";
	cin>>item;
	if(((RA==size+lb-1)&&(FA==lb))||(RA==FA-1)) {
		cout<<"Circular Queue is Full\n";
		return;
	}
	if(RA==size+lb-1){
		RA=lb;  
	} 
	else if(RA==lb-1){
		RA=lb;
		FA=lb; 
	}
	else
		RA++;
		Q[RA]=item;
	cout<<"Inserted value is: "<<Q[RA]<<"\n"; 
}
void Circular_Deletion(){
	if(FA==lb-1){
		cout<<"Circular Queue is Empty\n";
		return; 
	}
	item=Q[FA];
	if(FA==RA){
		RA=lb-1;
		FA=lb-1;  
	} 
	else if(FA==size+lb-1){
		FA=lb; 
	}
	else{
		FA++;
	}
	cout<<endl<<item<<" has been Deleted from Queue";  
}
void Display_CircularQueue(){
	if(FA==lb-1){ cout<<"\nQueue is Empty";
            return;
	}
    cout<<"\nQueue is";
    if(FA<=RA){
        for(int i=FA; i<=RA; i++){
            cout<<"\t["<<Q[i]<<"]";
		}
    }
	else{
    	for(int i=FA; i<=(size+lb-1); i++){
                cout<<"\t["<<Q[i]<<"]";
			}
            for(int i=lb; i<=RA; i++){
                cout<<"\t["<<Q[i]<<"]";   
			}
		}
	}
void Queue_SLL(){
	system("cls");
	cout<<" *\n\nQueue On Single Linked List\n\n";
		int choice;
		cout<<"1)Press 1 for Simple Queue on Single Linked List\n" 
	          "2)Press 2 for Circular Queue on Single Linked List\n"
		      "3)Press 3 for exit\n"; 
		cin>>choice;
			switch(choice){
			case 1: 	Simple_Queue_SLL();
					break;
			case 2:		Circular_Queue_SLL();
					break;
			case 3:     cout<<endl<<"Exiting Program";
                    	exit(0);
                	break;
	        default:	cout<<endl<<"Invalid Selection";
			}
		}
void Simple_Queue_SLL(){
		while(true){
		system("cls");
   		cout<<"\n\nSimple Queue On Single Linked List\n\n";
	    cout<<"1)Press 1 for Enqueue in Single linked list\n"
	          "2)Press 2 for Dequeue in Single linked list\n"
	          "3)Press 3 for Display Queue\n"
	          "4)Press 4 For Exit\n"
	          "Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:		Enqueue_SLL();
				break;
			case 2:		Dequeue_SLL();
				break;
			case 3:		Display_Q_SLL();
				break;
			case 4:  	exit(0);
				break;
			default:    cout<<"invalid input";
				break;    
			}
		}
	}
	void Enqueue_SLL(){
		Node*ptr=new Node();
		cout<<"Enter item which you want to insert: ";
		cin>>item;
		ptr->info=item;
		ptr->next=NULL;
		if(R==NULL){
			F=ptr;
			R=ptr;
		}
		else{	
			R->next=ptr;
		 	R=ptr;
		}
		cout<<item<<" is inserted"<<endl;
		system("pause");
	}
void Dequeue_SLL(){	
		if(F==NULL){	
			cout<<"Queue is empty";
			return;
			system("pause");
		}
		Node*ptr=F;
		if(F->next==NULL){	
			F=NULL;
			R=NULL;
		}
		else{
			F=F->next;
		}
		delete(ptr);
		cout<<"item is deleted from the Queue"<<endl;
		system("pause"); 
	} 
void Display_Q_SLL(){  
		if((R==NULL)&&(F==NULL)){
			cout<<"Queue is empty"<<endl;
			return;
			system("pause");  
		}
		Node*ptr=F;
		cout<<"Queue Single linked is : ";
		while(ptr!=NULL){ 
			cout<<" {"<<ptr->info<<"}";
			ptr=ptr->next;
		}
		cout<<endl;
		system("pause"); 
	}	
void Circular_Queue_SLL(){	
		while(true){
		system("cls");
  		cout<<" \n\nCircular Queue On Single Linked List\n\n";
		cout<<"1)Press 1 for EnCircular Queue in Single linked list\n"
		      "2)Press 2 for DeCircular Queue in Single linked list\n"
			  "3)Press 3 for Display Queue\n"
			  "4)Press 4 For Exit\n"
			  "Enter your choice: ";
		cin>>choice;
		switch(choice){	
		case 1:  	Encircularqueue_SLL();
			break;
		case 2:     Decircularqueue_SLL();
			break;
		case 3:     Display_CQ_SLL();
			break;
		case 4:     exit(0);
			break;
		default:	cout<<"InvalidIinput";
			break;
		}
	}
} 
void Encircularqueue_SLL(){   
		int item;
		Node*ptr=new Node();
		cout<<"Enter item which you want to insert: ";
		cin>>item;
		ptr->info=item;
	    if(R==NULL){
		    R=ptr;
		    F=ptr;
	    	R->next=F;  
		}	
	    else if(F==R){
			R=ptr;
	    	F->next=R;
	    	R->next=F;
		}
		else{
			R->next=ptr;
			R=ptr;
			R->next=F;   
		}
		cout<<item<<" is inserted"<<endl;
		system("pause");
	}
void Decircularqueue_SLL(){	
		if(F==NULL){  
			cout<<"Queue is empty";
			return;
			system("pause");  
		}
		Node*ptr=F;
		if(F==R){	
			F=NULL;
			R=NULL;  
		}
		else{		
			F=F->next;
			R->next=F;  
		}
		delete(ptr);
		cout<<"item is deleted from the Queue"<<endl;
		system("pause");   
	}
	void Display_CQ_SLL(){	
		if((R==NULL)&&(F==NULL)){	
			cout<<"Queue is empty"<<endl;
			return;
			system("pause");
		}		
		Node*ptr=F;
		cout<<"Queue Single linked is : ";	
		do{	
			cout<<" {"<<ptr->info<<"}";
			ptr=ptr->next;   
		}
		while(ptr!=F);
		cout<<endl;
        system("pause");    
	}
void Queue_DLL(){
	system("cls");
	cout<<"\n\nQueue On Double Linked List\n\n";
	int choice;
  	cout<<"1)Press 1 for Simple Queue on Double Linked List\n" 
		  "2)Press 2 for Circular Queue on Double Linked List\n"
		  "3)Press 3 for exit\n"; 
		cin>>choice;
			switch(choice){
				case 1:	    	Simple_Queue_DLL();
					break;
				case 2:			Circular_Queue_DLL();
					break;
			    case 3:         cout<<endl<<"Exiting Program";
                    exit(0);
                break;	
			    default:
			    	cout<<endl<<"Invalid Selection";
			}
		}
void Simple_Queue_DLL(){
		while(true){
		system("cls");
     	cout<<"\n\nSimple Queue On Double Linked List \n\n";
		cout<<"1)Press 1 for Enqueue in Double linked list\n"
			  "2)Press 2 for Dequeue in Double linked list\n"
			  "3)Press 3 for Display Queue\n"
			  "4)Press 4 For Exit\n"
			  "Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:   Enqueue_DLL();
				break;
			case 2: 	Dequeue_DLL();
				break;
			case 3:    Display_Q_DLL();
				break;
			case 4:		exit(0);
				break;
			default:	cout<<"invalid input";
				break;   
		}
	}
}
void Enqueue_DLL(){
		Node*ptr=new Node();
		cout<<"Enter item which you want to insert: ";
		cin>>item;
		ptr->info=item;
		ptr->next=NULL;
		ptr->prev=R;
		if(R==NULL)
		{	
			F=ptr;
			R=ptr;
		}
		else{
			R->next=ptr;
			R=ptr;  
		}
		cout<<item<<" Is inserted"<<endl;
		system("pause");   
	}
void Dequeue_DLL(){	
		if(F==NULL)
		{		
			cout<<"Queue is empty";
			return;
			system("pause");   
		}
		Node*ptr=F;
		if(F->next==NULL)
		{	
			F=NULL;
			R=NULL;  
		}
		else
		{	F=F->next;
			F->prev=NULL;  
		}
		delete(ptr);
		cout<<"item is deleted from the Queue"<<endl;
		system("pause");  
	}
void Display_Q_DLL(){	
	if((R==NULL)&&(F==NULL)){
		cout<<"Queue is empty"<<endl;
		return;
		system("pause"); 
	}
	Node*ptr=F;
	cout<<"Queue Single linked is : ";
	while(ptr!=NULL)
	{
		cout<<" ["<<ptr->info<<"]";
		ptr=ptr->next;
	}
	cout<<endl;
	system("pause");  
}
void Circular_Queue_DLL(){	
		while(true){
		system("cls");
		cout<<" \n\nCircular Queue On Double Linked List \n\n";
		cout<<"1)Press 1 for EnCircular Queue in Double linked list\n"
			  "2)Press 2 for DeCircular Queue in Double linked list\n"
			  "3)Press 3 for Display Queue\n"
		   	  "4)Press 4 For Exit\n"
			  "Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:		Encircularqueue_DLL();
				break;
			case 2:		Decircularqueue_DLL();
				break;
			case 3:		Display_CQ_DLL();
				break;
			case 4:  	exit(0);
				break;
			default:    cout<<"invalid input";
				break;
			}
		}
	}
void Encircularqueue_DLL(){   
		int item;
		Node*ptr=new Node();
		cout<<"Enter item which you want to insert: ";
		cin>>item;
		ptr->info=item;
	    if(R==NULL) {
	    R=ptr;
	    F=ptr;
	    R->next=F;
		F->prev=R;	}
	    else if(R==F)
	    { 	R=ptr;
	        F->next=R;
	        R->next=F;
	        R->prev=F;
	        F->prev=R;}
		else
		{   R->next=ptr;
			ptr->prev=R;
	        R=ptr;
	        R->next=F;
	        F->prev=R;}
		cout<<item<<" is inserted"<<endl;
		system("pause");
	}
void Decircularqueue_DLL(){	
		if(F==NULL){	
			cout<<"Queue is empty";
			return;
			system("pause");  
		}
		Node*ptr=F;
		if(F==R)
		{	F=NULL;
			R=NULL;  
		}
		else
		{	F=F->next;
			F->prev=R;
			R->next=F;  
		}
		delete(ptr);
		cout<<"item is deleted from the Queue"<<endl;
		system("pause");   
	}
void Display_CQ_DLL(){	
		if((R==NULL)&&(F==NULL)){	
			cout<<"Queue is empty"<<endl;
			return;
			system("pause");  
		}
		Node*ptr=F;
		cout<<"Queue  : ";
		do{	
			cout<<" {"<<ptr->info<<"}";
			ptr=ptr->next;
		}
		while(ptr!=F);
		cout<<endl;
        system("pause"); 
	}  
 void TREE(){
 	while(true){
 	cout<<"\n\n DATA STRUCTURE OF TREE\n\n"
          "Enter Your Choice\n"
       	  "1) Press 1 For Create Tree\n"
		  "2) Press 2 For Traverse Tree\n"
		  "3) Press 3 For BST\n"
		  "4) Press 4 For AVL\n"
		  "5) Press 5 For Heap\n"
		  "6) Press 6 For Exit\n";
	cin>>choice;
		switch(choice){
			case 1:  	Create_Tree();
				break;
			case 2:     Traverse_Tree();
					break;  
			case 3:
			      BST();
					break;
			case 4:
			      AVL();
			      break;
		    case 5:  Heap();
			      	break;		
			case 6:
					cout<<"Exiting Program";
			    	exit(0);
			default:
			  	cout<<endl<<"Invalid Selection";   
				}
			}
		}
void Create_Tree(){
	   	root=new Node();
		Create_subtree(root);
	}
void Create_subtree(Node*root){
			cout<<"Enter Item";
			cin>>item;
			root->info=item;
			string op_left;
			cout << "Does the node have a left child 'yes' or 'no'";
			cin >> op_left;
			if (op_left=="yes"){
				root->left=new Node();
				Create_subtree(root->left);}
			else{	
				root->left=NULL;  
			}
				string op_right;
				cout << "Does the node have a right child 'yes' or 'no' ";
				cin>>op_right;
			if(op_right=="yes"){
				root->right=new Node();
				Create_subtree(root->right);}
				else{	
					root->right=NULL;   
				}   
		}
void Traverse_Tree(){
		while(true){	
		cout<<"Enter your choice\n"
			  "1) Press 1 For Preorder Traverse\n"
			  "2) Press 2 For Inorder Traverse\n"
			  "3) Press 3 For Postorder Traverse\n";
		cin>>choice;
		switch(choice){
			case 1:     Preorder_Traverse(root);
				  		break;
			case 2:	    Inorder_Traverse(root);
				  		break;
			case 3: 	Postorder_Traverse(root);
						break;
			default:	cout<<"Inavlid Selection";
		}
	}
}
void Preorder_Traverse(Node*root){
		cout<<"[ "<<root->info<<" ]";
		if(root->left!=NULL){
			Preorder_Traverse(root->left);  
		}
		if(root->right!=NULL){
			Preorder_Traverse(root->right);   
		}
	}
void Inorder_Traverse(Node*root){
	if(root->left!=NULL){
		Inorder_Traverse(root->left);   
	}
		cout<<"[ "<<root->info<<" ]";
		if(root->right!=NULL){
		Inorder_Traverse(root->right);   
		}
	}
void Postorder_Traverse(Node*root){
			if(root->left!=NULL){
			Postorder_Traverse(root->left);  }
		if(root->right!=NULL){
			Postorder_Traverse(root->right);   }
		cout<<"[ "<<root->info<<" ]";	  
	}
//bst
void BST(){
	  while(1){
	  	system("cls");
		cout<<"Enter your choice\n"
			  "1) Press 1 For BST_Insert\n"
			  "2) Press 2 For BST_Delete\n"
			  "3) Press 3 For  BST_Search\n"	
			  "4) Press 4 For Traverse\n"		
			  "5) Press 5 For return to main menu\n"
			  "6) Press 6 For Exit\n"	;
		cin>>choice;
		switch(choice){
			case 1: cout<<"Enter the value you want to insert";
	                cin>>item;
			    	root=BST_Insert(root,item);
					break;
			case 2: cout<<"Enter the value you want to delete";
	                cin>>item;
			     	root=BST_Delete(root,item);
			    	break;
			case 3: BST_Search();
			    	break;
		//	case 4:   BST_Traverse();
			    	break;
		    case 5:	TREE();
		        	break;
	        case 6:{	
					cout<<"Exiting Program";
			    	exit(0);
			}
			default:	cout<<"Inavlid Selection";	
			}
		}
	}
	Node*BST_Insert(Node*root,int item){
     	if(root==NULL){
		Node*ptr=new Node;
		ptr->info=item;
		ptr->left=NULL;
		ptr->right=NULL;
		root=ptr;
		return root;}
		if((root->info)>item){
			root->left=BST_Insert(root->left,item);
			cout<<"item inserted on left child\n";
			system("pause");
		}
		else{
			if((root->info)<item){
		    	root->right=BST_Insert(root->right,item);
			    cout<<"item inserted on right child\n";
				system("pause");
			}		
	     	else{
		     	cout<<"given item already exist\n";
		     	system("pause");
			}
		}
		return root;
	}
	Node*BST_Delete(Node*root,int item){
			if(root==NULL){
				cout<<"item not found";
				system("pause");
				return root; 
			}
		    if(root->info>item){
		    	root->left=BST_Delete(root->left,item);	}
		    else if(root->info<item){
            root->right=BST_Delete(root->right,item);  }	
            else{
           	if(root->left==NULL){
           	  Node*ptr=root->right;
           	  delete(root);
           	  return ptr;  
			}
			else if(root->right==NULL){	
                Node*ptr=root->left;
                delete(root);
                return ptr;	 
			}
			else{
                Node*ptr;
                ptr=Inordersuccessor(root);
                root->info=ptr->info;
                root->right=BST_Delete(root->right,ptr->info);}
            } 
			return root;
		}
		Node*Inordersuccessor(Node*root){ 
		  	Node*ptr=root->right;
        	while(ptr->left!= NULL){ 
			ptr = ptr->left;  }
        	return ptr;
		}     
void BST_Search(){
   	  	while(true){
		//	 system("cls");
	cout<<"1) Press 1 To Find Min Value\n"
      	  "2) Press 2 to find Max value\n"
      	  "3) Press 3 for single search\n"
      	  "4) Press 3 for  Return to Menu\n"
	  	  "5)Press 4 for exit \n"
      	  "Enter Your Choice";
	cin>>choice;
	switch(choice){
		case 1:  	Search_Min_BST();
			break;
		case 2:     Search_Max_BST();
				break;
		case 3:     Single_Search();
		      break;
		case 4:		BST();
					break;
		case 5:	{
				cout<<"Exiting Program";
			    	exit(0);}
		default:  cout<<endl<<"Invalid Selection";
		}
	}
}
void Search_Min_BST(){
	if(root==NULL){
		cout<<"Given Search tree is empty";
		return;
	}
	Node*ptr=root;
	while(ptr->left!=NULL){
		ptr=ptr->left;
	}
	cout<<"["<<ptr->info<<"]";
	system("pause");
	}
void Search_Max_BST(){
	if(root==NULL){
		cout<<"Given Search tree is empty";
		return;
	}
	Node*ptr=root;
	while(ptr->right!=NULL){
		ptr=ptr->right;
	}
	cout<<"["<<ptr->info<<"]";
	system("pause");
	}
void Single_Search(){
	//	if(root==NULL){
	//	cout<<"Given Search tree is empty";
	//	return;}
	     cout<<"\nEnter value that you want to search";
          cin>>item;
       Node*ptr=root;
        	while(ptr!=NULL){
			if(ptr->info==item){ 
			  	cout<<"item Found";
				ptr=NULL;
                delete(ptr);
                return;
			}
             ptr=ptr->next;
			}
		    cout<<"item not Found";
	     	ptr=NULL;
            delete(ptr);
		}
    void  AVL(){
        Root = NULL;
        while (true){
            system("cls");
            cout << "(In AVL Tree Menu)\n"
                    "Press\n"
                    "1)Traversal\n"
                    "2)Insertion in AVL\n"
                    "3)Deletion in AVL\n"
                    "4)Searching\n"
                    "5)Return to Main Menu\t";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Traverse();
            }
            break;
            case 2:
            {
                cout << "Enter the item you want to Insert\t";
                cin >> item;
                Root = Insert_AVL(Root, item);
            }
            break;
            case 3:
            {
                cout << "Enter the item you want to Delete\t";
                cin >> item;
                Root = Delete_AVL(Root, item);
            }
            break;
            case 4:
            {
                Avl_Searching();
            }
            break;
            case 5:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Invalid Choice\n";
                system("pause");
            }
            break;
            }
        }
    }
// Traverse
    void Traversal()
    {
        if (Root == NULL)
        {
            std::cout << "Empty Tree\n";
            system("pause");
            return;
        }
        while (1)
        {
            system("cls");
            std::cout << "(In AVL Tree Traversal Menu)\n"
                         "Press\n"
                         "1)PreOrder Traversal\n"
                         "2)InOrder Traversal\n"
                         "3)PostOrder Traversal\n"
                         "4)Return to Tree Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::cout << "Tree values are:\n";
                PreOrder_Trav(Root);
                system("pause");
            }
            break;
            case 2:
            {
                std::cout << "Tree values are:\n";
                InOrder_Trav(Root);
                system("pause");
            }
            break;
            case 3:
            {
                std::cout << "Tree values are:\n";
                PostOrder_Trav(Root);
                system("pause");
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Invalid Choice\n";
                system("pause");
            }
            break;
            }
        }
    }

    // PreOrder Traversal
    void PreOrder_Trav(Node_AVL *ptr)
    {
        std::cout << "[" << ptr->info << "]\t";

        if (ptr->Left != NULL)
        {
            PreOrder_Trav(ptr->Left);
        }

        if (ptr->Right != NULL)
        {
            PreOrder_Trav(ptr->Right);
        }
    }

    // InOrder Traversal
    void InOrder_Trav(Node_AVL *ptr)
    {
        if (ptr->Left != NULL)
        {
            InOrder_Trav(ptr->Left);
        }

        std::cout << "[" << ptr->info << "]\t";

        if (ptr->Right != NULL)
        {
            InOrder_Trav(ptr->Right);
        }
    }

    // PostOrder Traversal
    void PostOrder_Trav(Node_AVL *ptr)
    {
        if (ptr->Left != NULL)
        {
            PostOrder_Trav(ptr->Left);
        }

        if (ptr->Right != NULL)
        {
            PostOrder_Trav(ptr->Right);
        }

        std::cout << "[" << ptr->info << "]\t";
    }

    // Get Height
    int getHeight(Node_AVL *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        else
        {
            return ptr->height;
        }
    }

    // Balance Factor
    int getBalanceFactor(Node_AVL *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        return getHeight(ptr->Left) - getHeight(ptr->Right);
    }
    // LL Rotation
    Node_AVL *LL_Rotate(Node_AVL *ptr)
    {
        Node_AVL *ptr1 = ptr->Left;
        ptr->Left = ptr1->Right;
        ptr1->Right = ptr;

        ptr->height = std::max(getHeight(ptr->Left), getHeight(ptr->Right)) + 1;
        ptr1->height = std::max(getHeight(ptr1->Left), getHeight(ptr1->Right)) + 1;

        return ptr1;
    }

    // RR Rotation
    Node_AVL *RR_Rotate(Node_AVL *ptr)
    {
        Node_AVL *ptr1 = ptr->Right;
        ptr->Right = ptr1->Left;
        ptr1->Left = ptr;

        ptr->height = std::max(getHeight(ptr->Left), getHeight(ptr->Right)) + 1;
        ptr1->height = std::max(getHeight(ptr1->Left), getHeight(ptr1->Right)) + 1;

        return ptr1;
    }

    // LR Rotation
    Node_AVL *LR_Rotate(Node_AVL *ptr)
    {
        ptr->Left = RR_Rotate(ptr->Left);
        ptr = LL_Rotate(ptr);
        return ptr;
    }

    // RL Rotation
    Node_AVL *RL_Rotate(Node_AVL *ptr)
    {
        ptr->Right = LL_Rotate(ptr->Right);
        ptr = RR_Rotate(ptr);
        return ptr;
    }

    // Insertion in AVL
    Node_AVL *Insert_AVL(Node_AVL *Root, int item)
    {
        if (Root == NULL)
        {
            Node_AVL *Node = new Node_AVL();
            Node->info = item;
            Node->Left = NULL;
            Node->Right = NULL;
            Node->height = 1;
            return Node;
        }
        if ((Root->info) > item)
        {
            Root->Left = Insert_AVL(Root->Left, item);
        }
        else
        {
            if ((Root->info) < item)
            {
                Root->Right = Insert_AVL(Root->Right, item);
            }
            else
            {
                cout << "Item already exist\n";
                system("pause");
            }
        }

        Root->height = 1 + std::max(getHeight(Root->Left), getHeight(Root->Right));
        //        int BF = getBalanceFactor(Root);

        if ((getBalanceFactor(Root) == 2) && (getBalanceFactor(Root->Left) == 1))
        {
            Root = LL_Rotate(Root);
        }
        else if ((getBalanceFactor(Root) == -2) && (getBalanceFactor(Root->Right) == -1))
        {
            Root = RR_Rotate(Root);
        }
        else if (((getBalanceFactor(Root) == 2) && (getBalanceFactor(Root->Left) == -1)))
        {
            Root = LR_Rotate(Root);
        }
        else if ((getBalanceFactor(Root) == -2) && (getBalanceFactor(Root->Right) == 1))
        {
            Root = RL_Rotate(Root);
        }
        return Root;
    }

    // InOrder Successor
    Node_AVL *InOrderSuccessor(Node_AVL *Root)
    {
        Node_AVL *ptr = Root->Right;
        while (ptr->Left != NULL)
        {
            ptr = ptr->Left;
        }
        return ptr;
    }

    // Deletion in AVL
    Node_AVL *Delete_AVL(Node_AVL *Root, int item)
    {
        if (Root == NULL)
        {
            cout << "Item not Found\n";
            system("pause");
            return Root;
        }
        if (Root->Left == NULL && Root->Right == NULL)
        {
            delete (Root);
            return NULL;
        }
        if (item < Root->info)
        {
            Root->Left = Delete_AVL(Root->Left, item);
        }
        else if (item > Root->info)
        {
            Root->Right = Delete_AVL(Root->Right, item);
        }
        else
        {
            Node_AVL *ptr;
            ptr = InOrderSuccessor(Root);
            Root->info = ptr->info;
            Root->Right = Delete_AVL(Root->Right, ptr->info);
        }

        Root->height = 1 + std::max(getHeight(Root->Left), getHeight(Root->Right));

        if (getBalanceFactor(Root) == 2 && getBalanceFactor(Root->Left) == 1)
        {
            Root = LL_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == 2 && getBalanceFactor(Root->Left) == -1)
        {
            Root = LR_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == 2 && getBalanceFactor(Root->Left) == 0)
        {
            Root = LL_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == -2 && getBalanceFactor(Root->Right) == -1)
        {
            Root = RR_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == -2 && getBalanceFactor(Root->Right) == 1)
        {
            Root = RL_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == -2 && getBalanceFactor(Root->Right) == 0)
        {
            Root = RR_Rotate(Root);
        }
        return Root;
    }

    // Searching
    void Avl_Searching()
    {
        if (Root == NULL)
        {
            cout << "Empty Tree\n";
            system("pause");
            return;
        }
        while (1)
        {
           system("cls");
            cout << "(In AVL Tree Searching Menu)\n"
                         "Press\n"
                         "1)Search Minimum\n"
                         "2)Search Maximum\n"
                         "3)Search By Item\n"
                         "4)Return to AVL Tree Menu\t";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Search_Min();
                system("pause");
            }
            break;
            case 2:
            {
                Search_Max();
                system("pause");
            }
            break;
            case 3:
            {
    
				cout << "Enter Item you want to search\t";
                cin >> item;
                count = 0;
                Search_Item(Root);
                if (count == 0)
                {
                    cout << "Item not Found\n";
                }
                else
                {
                    cout << "Item Found\n";
                }
                system("pause");
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
            {
            cout << "Invalid Choice\n";
                system("pause");
            }
            break;
            }
        }
    }

    // Search Miminum
    void Search_Min()
    {
        Node_AVL *ptr = Root;

        while (ptr->Left != NULL)
        {
            ptr = ptr->Left;
        }
        cout << "Mininmum Value is\t" << ptr->info << std::endl;
    }

    // Maximum Value
    void Search_Max()
    {
        Node_AVL *ptr = Root;

        while (ptr->Right != NULL)
        {
            ptr = ptr->Right;
        }
        cout << "Mininmum Value is\t" << ptr->info << std::endl;
    }

    // Search by Value
    void Search_Item(Node_AVL *ptr)
    {
        if (ptr->info == item)
        {
            count++;
        }
        if (ptr->Left != NULL)
        {
            Search_Item(ptr->Left);
        }
        if (ptr->Right != NULL)
        {
            Search_Item(ptr->Right);
        }
    }
  void Heap(){
     int option;
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Max Heap" << endl;
        cout << "2. Min Heap" << endl;
        cout << "3. Exit" << endl;
        cout << "4. printBFS" << endl;
        cout << "Enter option: ";
        cin >> option;

        if (option == 1 || option == 2) {
            int operation;
            cout << "Select an operation:" << endl;
            cout << "1. Insertion" << endl;
            cout << "2. Deletion" << endl;
            cout << "Enter operation: ";
            cin >> operation;

            if (operation == 1) {
                int num;
                cout << "Enter the number of elements: ";
                cin >> num;

                cout << "Enter the elements: ";
                for (int i = 0; i < num; i++) {
                    int element;
                    cin >> element;
                    if (option == 1) {
                        insertMaxHeap(element);
                    } else if (option == 2) {
                        insertMinHeap(element);
                    }
                }
                if (option == 1) {
                    cout << "Max Heap: ";
                     cout<<"Max Heap using bfs"<<endl;
                    printBFS() ;
                //    printQueue();
                } else if (option == 2) {
                    cout << "Min Heap: ";
                     cout<<"Min Heap using bfs"<<endl;
                    printBFS() ;
                  //  printQueue();
                  //  cout<<"Min Heap using bfs"<<endl;
                    //printBFS() ;
                }
            } else if (operation == 2) {
                if (option == 1) {
                    cout << "Extracted Max Element: " << extractMax() << endl;
                    cout << "Max Heap: ";
                    cout<<"Max Heap using bfs"<<endl;
                    printBFS() ;
                    //printQueue();
                } else if (option == 2) {
                    cout << "Extracted Min Element: " << extractMin() << endl;
                    cout << "Min Heap: ";
                    //printQueue();
                    cout<<"Min Heap using bfs"<<endl;
                    printBFS() ;
                }
            } else {
                cout << "Invalid operation. Please try again." << endl;
            }
        } else if (option == 3) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
  printBFS();
   // return 0;
  }
void shiftUpMinHeap(int i) {
    // min heap
    while (i > 1 && H[parent(i)] > H[i]) {
        // do swapping
        int temp = H[parent(i)];
        H[parent(i)] = H[i];
        H[i] = temp;

        i = parent(i);
    }
}
void insertMinHeap(int p) {
    size = size + 1;
    H[size] = p;
    // Shift Up to maintain heap property
    shiftUpMinHeap(size);
}
int leftChild(int i) {
    return (2 * i);
}
int rightChild(int i) {
    return (2 * i) + 1;
}
void shiftDownMinHeap(int i) {
    int minIndex = i;

    // Left Child
    int l = leftChild(i);
    if (l <= size && H[l] < H[minIndex]) {
        minIndex = l;
    }

    // Right Child
    int r = rightChild(i);
    if (r <= size && H[r] < H[minIndex]) {
        minIndex = r;
    }

    // If i is not the same as minIndex
    if (i != minIndex) {
        swap(H[i], H[minIndex]);
        shiftDownMinHeap(minIndex);
    }
}
int extractMin() {
    int result = H[1];
    H[1] = H[size];
    size = size - 1;
    shiftDownMinHeap(1);
    return result;
}
void shiftUpMaxHeap(int i) {
    // max heap
    while (i > 1 && H[parent(i)] < H[i]) {
        // do swapping
        int temp = H[parent(i)];
        H[parent(i)] = H[i];
        H[i] = temp;

        i = parent(i);
    }
}

void insertMaxHeap(int p) {
    size = size + 1;
    H[size] = p;
    // Shift Up to maintain heap property
    shiftUpMaxHeap(size);
}
void shiftDownMaxHeap(int i) {
    int maxIndex = i;

    // Left Child
    int l = leftChild(i);
    if (l <= size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    // If i is not the same as maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDownMaxHeap(maxIndex);
    }
}
int extractMax() {
    int result = H[1];
    H[1] = H[size];
    size = size - 1;
    shiftDownMaxHeap(1);
    return result;
}
void printQueue() {
    for (int i = 1; i <= size; i++) {
        cout << H[i] << " ";
        void printBFS();
    }
    cout << endl;
}
void printBFS() {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    queue<int> q;
    q.push(1); // Start with the root node (index 1)

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << H[current] << " ";

        int left = leftChild(current);
        int right = rightChild(current);

        if (left <= size)
            q.push(left);

        if (right <= size)
            q.push(right);
    }
 }
};
int main(){
	DSA_proj DSA_proj;
}
















