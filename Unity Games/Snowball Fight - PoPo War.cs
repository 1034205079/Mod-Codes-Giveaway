//Game: Snowball Fight - PoPo War
//Version: 1.02
//APK: https://apkpure.com/snowball-fight-popo-war/com.yymoon.snowball

//UIRoot
	public void OnGUI()
	{
		ModMenu.OnGUI();
	}

//t_skill
public int cd
		{
			get
			{
				int num = this.cd;
				if (this.type == 1)
				{
					if (bp.animal.is_ai > 0)
					{
						if (bp.animal.type == unit_type.Player)
						{
							num = Config.get_t_ai_attr(bp.animal.is_ai).attack_t;
						}
						if (Battle.is_newplayer_guide)
						{
							num = 800;
						}
					}
					else
					{
						num = BattleOperation.toInt((double)this.cd / (1.0 + (double)bp.attr_value[92] / 100.0));
					}
				}
				if (bp.animal.type == unit_type.Player && bp.animal.is_ai > 0 && this.type == 1)
				{
					num = Config.get_t_ai_attr(bp.animal.is_ai).attack_t;
				}
				if (this.type == 2)
				{
					double num2 = 1.0 - (double)(bp.attr_value[23] + bp.get_skill_attr_value(this.id, 7)) / 100.0;
					num = BattleOperation.toInt((double)num * num2);
					if (Battle.is_newplayer_guide)
					{
						num = 800;
					}
				}
				if (this.type == 3)
				{
					double num3 = 1.0 - (double)bp.attr_value[24] / 100.0;
					num = BattleOperation.toInt((double)num * num3);
					if (Battle.is_newplayer_guide)
					{
						num = 800;
					}
				}
				if (Battle.is_newplayer_guide && bp.animal.is_ai > 0 && this.type == 1)
				{
					num = 800;
				}
				if (ModMenu.mod1) //high attack
				{
					return 0;
				}
				return num;
			}
		}