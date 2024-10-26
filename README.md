# Random Door Dungeon 
This is a repo where I attempt to develop a simple game. 

To run it use:

$ g++ -c *.c++ && g++ *.o -o Random_Door_Dungeon.out -lsfml-graphics -lsfml-window -lsfml-system && Random_Door_Dungeon.out

Check out [SFML and Linux](https://www.sfml-dev.org/tutorials/2.6/start-linux.php) for more information.

# Open Questions
Within the Game::initializeDoors(), there's a couple of sections commented out.
For some reason the game didn't work like intented within those sections.

### Commented out section 1
```
//        if(*DoorTypeSetIterator == 0) {
//            aDoor.loadClubSprite();
//        }
```

The textures for the sprite wouldn't load. They would render a blank Sprite.
My hypothesis is that when calling `mWeaponSprite` within `Game::render()` a copy of the sprite is being called
instead of the reference, causing issues.

### Commented out section 2
```
//        if(*DoorTypeSetIterator == 0) {
//            mDoors[i].loadClubSprite();
//        }
```

The texture would load only when i=2. Meaning, when `mDoors` reached its max size.
My hypothesis is that for some reason one needs to wait for `mDoors` to be completely filled before using it.

Which is I came up with the following solution:

I had to do a whole new loop because the code didn't behave the way that I though it would.
You may find that loop after the following comment:
```
// Load respective weapon sprite
```

It's not the prettiest solution but, it works for now.