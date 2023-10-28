

def max(self):
    max_position = first()
    position = first()
    while(after(position) != None):
        position = after(position)
        if (position.element() > max_position.element()):
            max_position = position
    return max_position