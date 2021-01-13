#include <stdio.h>

#define NO_OF_STATES 3
#define NO_OF_EVENTS 2

typedef enum {
	open,
	closed,
	locked
} State;

typedef enum {
	push_pull,
	turn_key
} Events;

static State TransitionTable[NO_OF_STATES][NO_OF_EVENTS] = {
	{closed, open},
	{open, locked},
	{locked, closed}
};

struct Door {
	State state;
};

void PrintState(struct Door* instance) {
	switch(instance->state) {
		case open: {
			printf("The door is open\n");
			break;
		}
		case closed: {
			printf("The door is closed\n");
			break;
		}
		case locked: {
			printf("The door is locked\n");
			break;
		}
		default: {
			printf("Unknown state\n");
			break;
		}
	}
}

void LockDoor(struct Door* instance) {
	printf("Turning the key\n");
	const State current_state = instance->state;
	instance->state = TransitionTable[current_state][turn_key];
	PrintState(instance);
}

void MoveDoor(struct Door* instance) {
	printf("Pushing/pulling the door\n");
	const State current_state = instance->state;
	instance->state = TransitionTable[current_state][push_pull];
	PrintState(instance);
}

int main() {
	struct Door door;

	door.state = closed;
	PrintState(&door);
	LockDoor(&door);
	MoveDoor(&door);
	LockDoor(&door);
	MoveDoor(&door);
	LockDoor(&door);
	MoveDoor(&door);

	return 0;
}