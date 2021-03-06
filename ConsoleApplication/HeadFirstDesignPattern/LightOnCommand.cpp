import Command;
import Light;

class LightOnCommand : public Command
{
public:

	LightOnCommand(Light* newLight)
		: light(newLight)
	{
	}

	void execute() override
	{
		light->on();
	}

	void undo() override
	{
		light->off();
	}

private:

	Light* light;
};