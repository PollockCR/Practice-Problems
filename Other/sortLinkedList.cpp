// Sort a singly linked list

void quickSort( Node* start, Node* end )
{
  int temp, piv, i, wall;
  int size = 0;
  Node* ptr = start;
  while( ptr != end )
  {
    size++;
    ptr = ptr->next;
  }
  if( size <= 1 ){}
  else if( size == 2 )
  {
    if( *start > *end )
    {
      temp = *start;
      *start = *end;
      *end = temp;
    }
  }
  else
  {
    piv = *end;
    wall = start;
    for( ptr = start; ptr != end; ptr = ptr->next )
    {
      if( *ptr  < piv )
      {
        if( wall != ptr )
        {
          temp = *wall;
          *wall = *ptr;
          *ptr = temp;
        }
        wall = wall -> next;
      } 
    }
    if( *wall > piv )
    {
      *end = *wall;
      *wall = piv;
    }
    quickSort( start, wall );
    quickSort( wall->next, end );
  }
}
