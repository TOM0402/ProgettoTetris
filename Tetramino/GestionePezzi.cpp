#include "GestionePezzi.hpp"
void GestionePezzi::generateRandom() {

    srand(time(0));
    for (int i = 0; i < 5; i++) {
        if(rand()%2==0) {

        }else{

        }
    }

}

p_list GestionePezzi::append(Tetramino t) {
    if(pezzi==NULL){
        pezzi->t()=t;
        pezzi->next=NULL;
    }else {
        p_list p = pezzi;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new list;
        p = p->next;
        p->t() = t;
        p->next = NULL;
    }
    return pezzi;

}

p_list GestionePezzi::remove() {
    if (this->pezzi != nullptr) {
        p_list temp = pezzi;
        pezzi = pezzi->next;
        delete temp;
    }
}

/*


p_lista head_insert (p_lista head, int el){
    p_lista tmp_head ;
    tmp_head = new lista ;
    tmp_head->val = el ;
    tmp_head->next = head ;
    return(tmp_head) ;
}



p_lista append(p_lista head, int val){
    if(head==NULL){
        head=new lista;
        head->val=val;
        head->next=NULL;
    }
    else {
        p_lista p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new lista;
        p = p->next;
        p->val = val;
        p->next = NULL;
    }
    return head;
}*/