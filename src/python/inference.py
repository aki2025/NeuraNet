import numpy as np
from rl_model import RLAgent
from aerial_sdk_bridge import update_slices

# Load trained model (hypothetical)
agent = RLAgent(state_size=4, action_size=4)
agent.model.load_state_dict(torch.load("trained_model.pth"))

# Example state
state = [500.0, 100, 0.1, 5.0]
action = agent.get_action(state)
print(f"Predicted actions: {action}")

# Pass to C++ via binding
update_slices(action.tolist()) 
