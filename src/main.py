from mavsdk import System
import asyncio
from mavsdk import MissionItem
from xbox_controller import XboxOneController

if __name__ == "__main__":
    controller = XboxOneController()
    controller.start_controller()



