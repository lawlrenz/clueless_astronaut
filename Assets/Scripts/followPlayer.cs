using UnityEngine;
using System.Collections;

public class followPlayer : MonoBehaviour {
	
	public float xOffset = 0;
	public float yOffset = -10;
	public float zOffset = -10;
	
	void Update() {
		GameObject target = GameObject.Find("Player");
		this.transform.position = new Vector3(target.transform.position.x + xOffset,
		                                      target.transform.position.y + yOffset,
		                                      target.transform.position.z + zOffset);
	}
	
}