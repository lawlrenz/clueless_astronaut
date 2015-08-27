using UnityEngine;
using System.Collections;

public class patrolItem : MonoBehaviour {

	public float xOffsetp1;
	public float yOffsetp1;
	public float xOffsetp2;
	public float yOffsetp2;

	public float movSpeed;

	

	private float mod = 1;

	private Vector2 p1;
	private Vector2 p2;

	private float linearKomb = 50;

	void Start () {
		p1.x = this.transform.position.x + xOffsetp1;
		p1.y = this.transform.position.y + yOffsetp1;

		p2.x = this.transform.position.x + xOffsetp2;
		p2.y = this.transform.position.y + yOffsetp2;

	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void FixedUpdate(){
		if ((linearKomb > 100)||(linearKomb < 0)) {
			mod = mod * -1.0f;
		}
		linearKomb += mod * movSpeed * 0.01f;
		//this.transform.position.x = linearKomb * 0.01f * p1.x + (1 - linearKomb * 0.01f) * p2.x;
	}

}
