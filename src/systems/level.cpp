#include "level.h"
#include <format>
#include <raylib.h>
#include <string>
#include "../debug.h"


void LevelSystem::init() {
    this->level = 0;
    this->stage = 0;
    this->state->player_baked = false;
    this->level_timer = 0;
}

void LevelSystem::tick() {
    this->level_timer += GetFrameTime();
    if (this->state->player_baked) {
        if (IsKeyPressed(KEY_SPACE)) {
            this->state->player_baked = false;
            this->stage = 0;
        }
        return;
    }
    switch (this->level) {
        case 0:
            switch (this->stage) {
                case 0:
                case 1:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 2:
                    this->level = 1;
                    this->stage = 0;
                    this->level_timer = 0;
                    break;
            }
            break;
        case 1:
            switch (this->stage) {
                case 0:
                    this->state->player_position = {
                        this->state->ground_dimensions.x * 160.0f / 2 - 40.0f,
                        this->state->ground_dimensions.y * 160.0f / 2 - 80.0f,
                    };
                    stage++;
                    break;
                case 1:
                    if (this->level_timer > 3.0f) {
                        stage++;
                    }
                    break;
                case 2:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 3:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 2.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 2 }, { 6, 6 }, ObstacleColor::Red));
                    stage++;
                    break;
                case 4:
                    if (this->state->remaining_obstacles == 0) {
                        stage++;
                        this->level_timer = 0;
                    }
                    break;
                case 5:
                    if (this->level_timer > 1.0f) {
                        stage++;
                    }
                    break;
                case 6:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 7:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 2.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { 5, 10 }, ObstacleColor::Red));
                    
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Blue, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 5, 0 }, { 5, 10 }, ObstacleColor::Blue));
                    stage++;
                    break;
                case 8:
                    if (this->state->remaining_obstacles == 0) {
                        stage++;
                    }
                    break;
                case 9:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 2.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { 10, 2 }, ObstacleColor::Red));
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 2 }, { 10, 2 }, ObstacleColor::Green));
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Blue, 4.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 4 }, { 10, 2 }, ObstacleColor::Blue));
                    stage++;
                    break;
                case 10:
                    if (this->state->remaining_obstacles == 2) {
                        stage++;
                    }
                    break;
                case 11:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 6 }, { 10, 2 }, ObstacleColor::Red));
                    stage++;
                    break;
                case 12:
                    if (this->state->remaining_obstacles == 2) {
                        stage++;
                    }
                    break;
                case 13:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 8 }, { 10, 2 }, ObstacleColor::Green));
                    stage++;
                    break;
                case 14:
                    if (this->state->remaining_obstacles == 0) {
                        stage++;
                    }
                    break;
                case 15:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 16:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { 5, 10 }, ObstacleColor::Red));
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 5, 0 }, { 5, 10 }, ObstacleColor::Green));
                    stage++;
                    level++;
                    break;
            }
            break;
        case 2:
            switch (this->stage) {
                case 0:
                    if (!this->state->player_baked) {
                        stage++;
                    }
                    break;
                case 1:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 2:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 3:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { 5, 10 }, ObstacleColor::Red));
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 3.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 5, 0 }, { 5, 10 }, ObstacleColor::Green));
                    stage++;
                    break;
                case 4:
                    if (this->state->remaining_obstacles == 0) {
                        stage++;
                    }
                    break;
                case 5:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    break;
                case 6:
                    level++;
                    stage = 0;
                    break;
            }
            break;
        case 3:
            switch (this->stage) {
                case 0:
                    this->state->player_position = {
                        this->state->ground_dimensions.x * 160.0f / 2 - 40.0f,
                        this->state->ground_dimensions.y * 160.0f / 2 - 80.0f,
                    };
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 2.0f});
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 2.5f});
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Blue, 3.0f});

                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { 10, 1 }, ObstacleColor::Red));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 9 }, { 10, 1 }, ObstacleColor::Red));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 1 }, { 1, 8 }, ObstacleColor::Red));
                    this->state->waiting_obstacles.push_back(Obstacle({ 9, 1 }, { 1, 8 }, ObstacleColor::Red));

                    this->state->waiting_obstacles.push_back(Obstacle({ 1, 1 }, { 8, 1 }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 1, 8 }, { 8, 1 }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 1, 2 }, { 1, 6 }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 8, 2 }, { 1, 6 }, ObstacleColor::Green));

                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 2 }, { 6, 1 }, ObstacleColor::Blue));
                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 7 }, { 6, 1 }, ObstacleColor::Blue));
                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 3 }, { 1, 4 }, ObstacleColor::Blue));
                    this->state->waiting_obstacles.push_back(Obstacle({ 7, 3 }, { 1, 4 }, ObstacleColor::Blue));
                    stage++;
                    break;
                case 1:
                    if (this->state->remaining_obstacles > 8) {
                        break;
                    };
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Magenta, 1.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 3, 3 }, { 4, 1 }, ObstacleColor::Magenta));
                    this->state->waiting_obstacles.push_back(Obstacle({ 3, 6 }, { 4, 1 }, ObstacleColor::Magenta));
                    this->state->waiting_obstacles.push_back(Obstacle({ 3, 4 }, { 1, 2 }, ObstacleColor::Magenta));
                    this->state->waiting_obstacles.push_back(Obstacle({ 6, 4 }, { 1, 2 }, ObstacleColor::Magenta));
                    stage++;
                    break;
                case 2:
                    if (this->state->remaining_obstacles > 8) {
                        break;
                    };
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Cyan, 1.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 4, 4 }, { 2, 2 }, ObstacleColor::Cyan));
                    stage++;
                    break;
                case 3:
                    if (this->state->remaining_obstacles == 0) {
                        stage++;
                    }
                    break;
                case 4:
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 1.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 4, 4 }, { 2, 2 }, ObstacleColor::Red));
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 1.5f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 3, 3 }, { 4, 1 }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 3, 6 }, { 4, 1 }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 3, 4 }, { 1, 2 }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 6, 4 }, { 1, 2 }, ObstacleColor::Green));
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Blue, 2.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 2 }, { 6, 1 }, ObstacleColor::Blue));
                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 7 }, { 6, 1 }, ObstacleColor::Blue));
                    this->state->waiting_obstacles.push_back(Obstacle({ 2, 3 }, { 1, 4 }, ObstacleColor::Blue));
                    this->state->waiting_obstacles.push_back(Obstacle({ 7, 3 }, { 1, 4 }, ObstacleColor::Blue));
                    stage++;
                    break;
                case 5:
                    if (this->state->remaining_obstacles > 8) {
                        break;
                    };
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Magenta, 1.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 1, 1 }, { 8, 1 }, ObstacleColor::Magenta));
                    this->state->waiting_obstacles.push_back(Obstacle({ 1, 8 }, { 8, 1 }, ObstacleColor::Magenta));
                    this->state->waiting_obstacles.push_back(Obstacle({ 1, 2 }, { 1, 6 }, ObstacleColor::Magenta));
                    this->state->waiting_obstacles.push_back(Obstacle({ 8, 2 }, { 1, 6 }, ObstacleColor::Magenta));
                    stage++;
                    break;
                case 6:
                    if (this->state->remaining_obstacles > 8) {
                        break;
                    };
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Cyan, 1.0f});
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { 10, 1 }, ObstacleColor::Cyan));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 9 }, { 10, 1 }, ObstacleColor::Cyan));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 1 }, { 1, 8 }, ObstacleColor::Cyan));
                    this->state->waiting_obstacles.push_back(Obstacle({ 9, 1 }, { 1, 8 }, ObstacleColor::Cyan));
                    stage++;
                    break;
                case 7:
                    if (this->state->remaining_obstacles == 0) {
                        level++;
                        stage = 0;
                    }
                    break;
            }
            break;
        case 4:
            switch (this->stage) {
                case 0:
                    this->level_var_1 = 0;
                    this->level_var_2 = 0;
                    stage++;
                    break;
                case 1:
                    if (this->state->remaining_counters >= 2) {
                        break;
                    }
                    if ((!this->state->is_paused || this->state->paused_color != ObstacleColor::Red) && this->level_var_1 <= 9) {
                        this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 0.5f});
                        this->state->waiting_obstacles.push_back(Obstacle({ (float) level_var_1, 0 }, { 1, 10 }, ObstacleColor::Red));
                        this->level_var_1++;
                    }
                    if ((!this->state->is_paused || this->state->paused_color != ObstacleColor::Green) && this->level_var_2 <= 9) {
                        this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 0.5f});
                        this->state->waiting_obstacles.push_back(Obstacle({ 0, (float) level_var_2 }, { 10, 1 }, ObstacleColor::Green));
                        this->level_var_2++;
                    }
                    if (this->level_var_1 == 10 && this->level_var_2 == 10) {
                        stage++;
                    }
                    break;
                case 2:
                    this->level_var_1 = 0;
                    this->level_var_2 = 0;
                    stage++;
                    break;
                case 3:
                    if (this->state->remaining_counters >= 2) {
                        break;
                    }
                    if ((!this->state->is_paused || this->state->paused_color != ObstacleColor::Blue) && this->level_var_1 <= 9) {
                        this->state->waiting_counters.push_back(Counter{ObstacleColor::Blue, 0.5f});
                        this->state->waiting_obstacles.push_back(Obstacle({ (float) 9 - level_var_1, 0 }, { 1, 10 }, ObstacleColor::Blue));
                        this->level_var_1++;
                    }
                    if ((!this->state->is_paused || this->state->paused_color != ObstacleColor::Red) && this->level_var_2 <= 9) {
                        this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 0.5f});
                        this->state->waiting_obstacles.push_back(Obstacle({ 0, (float) 9 - level_var_2 }, { 10, 1 }, ObstacleColor::Red));
                        this->level_var_2++;
                    }
                    if (this->level_var_1 == 10 && this->level_var_2 == 10) {
                        stage++;
                    }
                    break;
                case 4:
                    level++;
                    stage = 0;
                    break;

            }
            break;
        case 5:
            switch (this->stage) {
                case 0:
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                    }
                    this->level_var_1 = 0;
                    break;
                case 1: {
                    if (this->state->remaining_obstacles > 0) {
                        break;
                    }
                    if (this->level_var_1 == 3) {
                        level++;
                        stage = 0;
                    }
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Red, 5.0f});
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Green, 5.0f});
                    this->state->waiting_counters.push_back(Counter{ObstacleColor::Blue, 5.0f});
                    ObstacleColor order[] = {ObstacleColor::Red, ObstacleColor::Green, ObstacleColor::Blue};
                    for (int i = 2; i > 0; i--)
                    {
                        int j = GetRandomValue(0, i);

                        ObstacleColor temp = order[i];
                        order[i] = order[j];
                        order[j] = temp;
                    }
                    this->state->waiting_obstacles.push_back(Obstacle({0, 0}, {5, 5}, order[0]));
                    this->state->waiting_obstacles.push_back(Obstacle({5, 0}, {5, 5}, order[1]));
                    this->state->waiting_obstacles.push_back(Obstacle({0, 5}, {5, 5}, order[2]));
                    this->state->waiting_obstacles.push_back(Obstacle({5, 5}, {5, 5}, order[0]));

                    this->state->waiting_obstacles.push_back(Obstacle({0, 0}, {5, 5}, order[2]));
                    this->state->waiting_obstacles.push_back(Obstacle({5, 0}, {5, 5}, order[0]));
                    this->state->waiting_obstacles.push_back(Obstacle({0, 5}, {5, 5}, order[1]));
                    this->state->waiting_obstacles.push_back(Obstacle({5, 5}, {5, 5}, order[2]));
                    level_var_1++;
                    break;
                }
            }
            break;
        case 6:
            switch (this->stage) {
                case 0:
                    level_timer = 0;
                    stage++;
                    break;
                case 1:
                    if (level_timer > 30 && this->state->remaining_obstacles == 0) {
                        level++;
                        stage = 0;
                        break;
                    }
                    if (this->state->remaining_counters >= 3) { 
                        break;
                    }
                    ObstacleColor new_color;
                    for (ObstacleColor color : {ObstacleColor::Red, ObstacleColor::Green, ObstacleColor::Blue}) {
                        bool found = false;
                        for (Counter counter : this->state->counters) {
                            if (color == counter.color) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            new_color = color;
                            break;
                        }
                    }
                    for (float x = 0; x < this->state->ground_dimensions.x; x++) {
                        for (float y = 0; y < this->state->ground_dimensions.y; y++) {
                            if (GetRandomValue(1, 100) > 80) { continue; }
                            this->state->waiting_obstacles.push_back(Obstacle(
                                {x, y}, {1, 1}, new_color
                            ));
                        }
                    }
                    this->state->waiting_counters.push_back(Counter(new_color, 5.0f));

                    break;
            }
            break;
        case 7:
            switch (this->stage) {
                case 0:
                    level_timer = 0;
                    this->state->ground_dimensions = { 5, 5 };
                    stage++;
                    break;
                case 1: {
                    if (level_timer > 20) {
                        level++;
                        stage = 0;
                    }
                    ObstacleColor color;
                    switch (((int) level_timer) % 3) {
                        case 0:
                            color = ObstacleColor::Red;
                            break;
                        case 1:
                            color = ObstacleColor::Green;
                            break;
                        case 2:
                            color = ObstacleColor::Blue;
                            break;
                    }
                    for (Counter counter : this->state->counters) {
                        if (counter.color == color) {
                            return;
                        }
                    }
                    this->state->waiting_counters.push_back(Counter(color, 3.0f));
                    this->state->waiting_obstacles.push_back(Obstacle(
                                { static_cast<float>(((int) (this->state->player_position.x / 160.0f)) - 2), static_cast<float>(((int) (this->state->player_position.y / 160.0f)) - 2) }, { 5, 5 }, color));

                    break;
                }
            }
            break;
        case 8:
            switch (this->stage) {
                case 0:
                    this->state->ground_dimensions = { 5, 5 };
                    if (IsKeyPressed(KEY_SPACE)) {
                        stage++;
                        this->level_timer = 0;
                    }
                    break;
                case 1:
                    if (this->level_timer > 2) {
                        stage++;
                        this->level_timer = 0;
                    }
                    break;
                case 2:
                    if (this->level_timer > 2) {
                        stage++;
                    }
                    break;
                case 3:
                    this->state->waiting_counters.push_back(Counter(ObstacleColor::Red, 10.0f));
                    this->state->waiting_counters.push_back(Counter(ObstacleColor::Green, 10.0f));
                    this->state->waiting_counters.push_back(Counter(ObstacleColor::Blue, 10.0f));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { this->state->ground_dimensions.x, this->state->ground_dimensions.y }, ObstacleColor::Red));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { this->state->ground_dimensions.x, this->state->ground_dimensions.y }, ObstacleColor::Green));
                    this->state->waiting_obstacles.push_back(Obstacle({ 0, 0 }, { this->state->ground_dimensions.x, this->state->ground_dimensions.y }, ObstacleColor::Blue));
                    level++;
                    break;
            }
            break;
        case 9:
            switch (this->stage) {
                case 0:
                    if (IsKeyPressed(KEY_R)) {
                        level = 0;
                    }
                    break;
            }
            break;
        case 10:
            break;
    }
}

void LevelSystem::after_draw() {
    const int HEADER_FONT_SIZE = 150;
    const int SUBTITLE_FONT_SIZE = 50;
    bool clear_background = true;
    bool draw_overlay = false;
    std::string header;
    std::vector<std::string> subtitles;
    Color header_color = WHITE;

    if (this->level == 0) {
        if (this->stage == 0) {
            header = "Have you ever wondered...";
            subtitles = {"How do potatoes feel while being BAKED?", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
        if (this->stage == 1) {
            header = "I did not";
            subtitles = {"But you're about to find out", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
    }
    if (this->level == 1) {
        if (this->stage == 1) {
            header = "";
            subtitles = {"", "", "", "", "  Welcome to <>", "   Press arrow keys to move"};

            draw_overlay = true;
            clear_background = false;
        }
        if (this->stage == 2) {
            header = "Avoid the lit-up grates!";
            subtitles = {"They're gonna BAKE you once their timer runs out", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
        if (this->stage == 6) {
            header = "Congratulations!";
            subtitles = {"You have survived!", "...for now", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
        if (this->stage == 15) {
            header = "Seems easy...";
            subtitles = {"...until the whole floor lights up at once", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
    }
    if (this->level == 2) {
        if (this->stage == 1) {
            header = "See, there's one more thing";
            subtitles = {"I forgot to tell you", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
        if (this->stage == 2) {
            header = "You can PAUSE";
            subtitles = {"one of the timers!", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
        if (this->stage == 4) {
            header = "";
            subtitles = {"", "", "", "", "  Press <1>, <2>, ... to toggle timers", "  Note that only one timer may be paused at a time"};
            clear_background = false;
            draw_overlay = true;
        }
        if (this->stage == 5) {
            header = "That would be it";
            subtitles = {"When it comes to the tutorial", "Good luck!", "(You should know how to continue by now)"};
            draw_overlay = true;
        }
    }
    if (this->level == 5) {
        if (this->stage == 0) {
            header = "Did you notice the colors blend?";
            subtitles = {"Let's see if you can decode the primary colors behind them", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
    }
    if (this->level == 8) {
        if (this->stage == 0) {
            header = "You've been doing exceptionally well";
            subtitles = {"for a potato...", "Press <SPACE> to continue"};
            draw_overlay = true;
        }
    }
    if (this->level == 9) {
        if (this->stage == 0) {
            header = "Thank you for playing!";
            subtitles = {"You can press <R> to start from the begining"};
            draw_overlay = true;
        }
    }
    if (this->level == 10) {
        header = "Bonus level";
        subtitles = {"for those who glitched their way here"};
        draw_overlay = true;
    }
    if (this->state->player_baked) {
        if (this->level == 9) {
            header = "You got BAKED!";
            subtitles = {"Press <SPACE> to continue"};
            header_color = RED;
            draw_overlay = true;
        } else {
            header = "You got BAKED!";
            header_color = RED;
            subtitles = { std::format("Press <SPACE> to restart from level {}", this->level) };
            draw_overlay = true;
        }
    }
    if (draw_overlay) {
        const int header_width = MeasureText(header.c_str(), HEADER_FONT_SIZE);
        if (clear_background) {
            ClearBackground(BLACK);
        }
        DrawText(header.c_str(), GetScreenWidth() / 2 - header_width / 2, GetScreenHeight() / 2 - HEADER_FONT_SIZE / 2, HEADER_FONT_SIZE, header_color);

        for (size_t i = 0; i < subtitles.size(); i++) {
            const std::string subtitle = subtitles[i];
            const int subtitle_width = MeasureText(subtitle.c_str(), SUBTITLE_FONT_SIZE);
            DrawText(subtitle.c_str(), GetScreenWidth() / 2 - subtitle_width / 2, GetScreenHeight() / 2 + HEADER_FONT_SIZE + i * 2 * SUBTITLE_FONT_SIZE, SUBTITLE_FONT_SIZE, WHITE);
        }
    }
}
